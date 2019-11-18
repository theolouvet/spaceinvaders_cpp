#include "../header/spaceshooter.h"

#include<iostream>
#include <cstdlib>
#include <math.h>

//variables global dimension de la zone de jeu et position du heros
int W ,H;
int herox, heroy;


SpaceShooter::SpaceShooter(int w, int h)
    {

    extern int W,H;
    W=w;
    H=h;
    set_theme(1);
    hero=new Hero(W/2,3*H/4);
    hero->set_theme(this->get_theme());
    //fond du jeu
    fond = new SpaceFond();
 }
//SpaceShooter(int W, int H,int vie);
void SpaceShooter::initialisation(){

    if(get_theme()<=0 && get_theme()>3){
        set_theme(1);
    }

    hero->set_theme(this->get_theme());
    hero->init();

    delete fond;
    fond = new SpaceFond();
    bonuslist.clear();
    boucliers.clear();
    missile.clear();
    enemies.clear();
    enemymissile.clear();
    render_buffer.clear();


    //positionnement aléatoire des ennemies au debut du jeu
    int i;
    int y=-40;
    for(i=1;i!=50;)
    {
        int k;
        int x=0.2;
        int alea=rand()%5 +1+x;
        int alea2=rand()%100 +1;
        if(alea2<=30)
        {
            y=diagenemie(y);
        }
        else{
            for(k=1+x;k!=alea;)
            {
                if(rand()%10 +1<5)
                {
                    enemies.push_back(new EnemyPing(k*W/alea,y,get_theme()));
                }
                else{
                    enemies.push_back(new EnemyPong(k*W/alea,y,get_theme()));
                }
                k+=1;

            }
        }

        y-=50;
        i+=1;
        x+=0.2;



    }
    //generation du buffer de la zone de rendu, il contient tout les objet à afficher
    gen_render_buffer();
}




bool SpaceShooter::touche_ennemi(Drawable_Object* mis){

    //Parcour de la liste des ennemie
    std::list<Ennemy*>::iterator ite_enn ;
    for(ite_enn= enemies.begin();ite_enn != enemies.end();){
        Ennemy* enemie=*ite_enn;
        float x=enemie->get_x();
        float y=enemie->get_y();
        float xmis=mis->get_x();
        float ymis=mis->get_y();
        //calcul de la distance entre l'objet et l'ennemie
        float dist = sqrt((x-xmis)*(x-xmis)+(y-ymis)*(y-ymis));
        if (dist <= 20){//Si trop proche
            if (enemie->get_vie()==1){//Si l'ennemie a 1 point de vie
                //augmentation du score du hero
                hero->setScore(hero->getScore()+enemie->getPoint());
                //generation aleatoire d'un bonus
                int alea=rand()%100 +1;
                if(alea<=35){
                    add_bonus(new BonusVie(x,y));
                }
                else if(alea<=60){
                    add_bonus(new BonusBouclier(x,y));
                }
                //efface l'ennemie
                enemies.erase(ite_enn++);


            }
            else{
                enemie->set_vie(enemie->get_vie()-1);
            }

            return true;
        }
        else{

            ++ite_enn;

        }
    }
    return false;

}


void SpaceShooter::iteration(){
    extern int herox,heroy;

    //iteration hero
    hero->move();
    herox=hero->get_x();
    heroy=hero->get_y();
    //iteration du fond
    fond->move();
    //on ajoute les missiles generer par le hero
    add_missiles( hero->gen_missile());
    //mouvement des boucliers autour du hero
    for(auto bouc:boucliers){
        bouc->move();
    }

    //iteration bonus
    std::list<Bonus*>::iterator ite_bon ;
    for(ite_bon= bonuslist.begin();ite_bon != bonuslist.end();){
        Bonus* bon=*ite_bon;
        bool in_map =bon->move();
        if (in_map == false){//on efface le bonus si il sort de l'ecrran
            bonuslist.erase(ite_bon++);
        }
        else{
            if(touche_hero(bon)){//si il touche le hero
                int bonustype=bon->get_bonustype();

                switch (bonustype){
                    //vie
                    case(1):

                        hero->set_vie(hero->get_vie()+1);
                        break;
                    //bouclier
                    case(2):
                        std::list<Bouclier*> boucs;
                        boucs.push_back(new Bouclier(0));
                        boucs.push_back(new Bouclier(120));
                        boucs.push_back(new Bouclier(240));
                        add_boucliers(boucs);//ajout de 3 bouclier au heros
                        break;

                }
                bonuslist.erase(ite_bon++);
            }
            else{
                ++ite_bon;
            }

        }
    }

    //iteration missile hero
    std::list<Missile*>::iterator ite_miss ;
    for(ite_miss= missile.begin();ite_miss != missile.end();){
        Missile* mis=*ite_miss;
        bool in_map =mis->move();
        if (in_map == false){
            missile.erase(ite_miss++);
        }
        else{
            if(touche_ennemi(mis)){//si le missile touche un ennemie on l'efface
                                    // touche_ennemi() efface lui meme l'ennemi toucher
                missile.erase(ite_miss++);
            }
            else{
                ++ite_miss;
            }

        }
    }


    //iterations enemie
    std::list<Ennemy*>::iterator ite_enn ;
    for(ite_enn= enemies.begin();ite_enn != enemies.end();){
        Ennemy* enemie=*ite_enn;
        bool in_map =enemie->move();
        if (in_map == false){
            enemies.erase(ite_enn++);
        }
        else{
            //check collisions

            //avec le hero
            if (touche_hero(enemie)){
                //action si toucher

                    hero->set_vie(hero->get_vie()-1);


            }
            //ajout des missiles generer par l'ennemi
            add_enemymissiles( enemie->gen_missile());
            ++ite_enn;

        }
    }
    //iteration missile ennemy
    std::list<Missile*>::iterator ite_enn_miss ;
    for(ite_enn_miss= enemymissile.begin();ite_enn_miss != enemymissile.end();){
        Missile* mis=*ite_enn_miss;
        bool in_map =mis->move();
        if (in_map == false){
            enemymissile.erase(ite_enn_miss++);
        }
        else if(touche_hero(mis)){
            //check collision
           hero->set_vie(hero->get_vie()-mis->get_degat());
           enemymissile.erase(ite_enn_miss++);
        }
        else if(touche_bouclier(mis)){
            enemymissile.erase(ite_enn_miss++);
        }

        else{
            ++ite_enn_miss;
        }
    }
    //regeneration du buffer de la zone de rendu
    gen_render_buffer();

}



bool SpaceShooter::touche_hero(Drawable_Object* obj){
    float xhero=hero->get_x();
    float yhero=hero->get_y();
    float xmis=obj->get_x();
    float ymis=obj->get_y();

    float dist = sqrt((xhero-xmis)*(xhero-xmis)+(yhero-ymis)*(yhero-ymis));

    return dist <= 20;
}



void SpaceShooter::init_hero(){
    hero->init();
}



void SpaceShooter::add_hero_speed(vec2 speed){
    hero->add_speed(speed);
}



void SpaceShooter::add_missile(Missile* missile){
    this->missile.push_back(missile);
}



void SpaceShooter::add_missiles(std::list<Missile*> missiles){

    for (auto missile:missiles)
        add_missile(missile);
}





void SpaceShooter::add_enemymissile(Missile* missile){
    this->enemymissile.push_back(missile);
}




void SpaceShooter::add_enemymissiles(std::list<Missile*> missiles){

    for (auto missile:missiles)

        add_enemymissile(missile);


}





void SpaceShooter::add_enemy(Ennemy* enemy){
    enemies.push_back(enemy);
}




void SpaceShooter::add_enemies(std::list<Ennemy*> enemies){

    for (auto enemy:enemies)
        add_enemy(enemy);
}



void SpaceShooter::add_bonus(Bonus* bonus){
    bonuslist.push_back(bonus);
}

std::list<Drawable_Object*> SpaceShooter::get_render_buffer(){
    return render_buffer;

}


bool SpaceShooter::touche_bouclier(Drawable_Object* mis){

    //iterations enemie
    std::list<Bouclier*>::iterator ite_bouc ;
    for(ite_bouc= boucliers.begin();ite_bouc != boucliers.end();){
        Bouclier* bouc=*ite_bouc;
        float x=bouc->get_x();
        float y=bouc->get_y();
        float xmis=mis->get_x();
        float ymis=mis->get_y();

        float dist = sqrt((x-xmis)*(x-xmis)+(y-ymis)*(y-ymis));
        if (dist <= 20){


                boucliers.erase(ite_bouc++);





            return true;
        }
        else{

            ++ite_bouc;

        }
    }
    return false;

}


void SpaceShooter::gen_render_buffer(){
    render_buffer.clear();
    render_buffer.push_front(hero);

    for(auto mis : missile)
        render_buffer.push_front(mis);

    for(auto enemy : enemies)
        render_buffer.push_front(enemy);

    for(auto missile : enemymissile)
        render_buffer.push_front(missile);

    for(auto bonus : bonuslist)
        render_buffer.push_front(bonus);

    for(auto bouc : boucliers)
        render_buffer.push_front(bouc);

    for(auto fon : fond->get_fond()){
        render_buffer.push_front(fon);
    }

}

//permet de renvoyer le score a windows pour le label
int SpaceShooter::getScore(){
    return hero->getScore();
}
int SpaceShooter::getVie(){
    return hero->get_vie();
}


// ajout d'un boucier dans la simulation
void SpaceShooter::add_bouclier(Bouclier* bouc){

    boucliers.push_front(bouc);

}
// ajout d'une liste de bouclier dans la simulation
void SpaceShooter::add_boucliers(std::list<Bouclier*> boucs){
    for(auto bouc : boucs){
        add_bouclier(bouc);
    }

}
void SpaceShooter::set_theme(int theme){
    this->theme=theme;
}
int SpaceShooter::get_theme(){
    return theme;
}
int SpaceShooter::diagenemie(int py){
    int i;
    int y=py;
    int alea1= rand()%2 +1;
    int alea2=rand()%100 +1;
    int a=10;
    if(alea1==1){
        a=0;
    }
    for(i=pow(-1,alea1);i!=10*pow(-1,alea1);){

        if(alea2<=50)
        {
            enemies.push_back(new EnemyPing((a-i)*W/10,y,get_theme()));
        }
        else{
            enemies.push_back(new EnemyPong((a-i)*W/10,y,get_theme()));
        }
        //std::cout<<(a-i)*W/10<<"  "<<y<<std::endl;
        y-=25;
        i+=pow(-1,alea1);
    }
    return y;

}
