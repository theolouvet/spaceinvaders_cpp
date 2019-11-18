#include "../header/hero.h"


//le hero a 5 vie et une vitesse de 10
Hero::Hero(float x, float y):Ship(x,y,5),speed(10),score(0)
{

}

//reinitialise le hero
void Hero::init(){
    set_image("image"+QString::number(get_theme())+"/vaisseau2.gif");
    set_scale(40,40);
    setScore(0);
    set_vie(5);
    speedvector=vec2(0,0);
    set_position(get_xini(),get_yini());


}
//fonction de génération de missiles en fonction de l'age du hero
std::list<Missile*> Hero::gen_missile(){
    std::list<Missile*> res;
    long long int age=get_age();

    if (age%5==0){
        float x = get_x();
        float y =get_y();
        res.push_back(new MissileHero(x,y,vec2(0,-1),get_theme()));
        if(getScore()>=60)
        {
        res.push_back(new MissileHero(x,y,vec2(-0.2,-1),get_theme()));
        res.push_back(new MissileHero(x,y,vec2(0.2,-1),get_theme()));
        }
    }

    return res;
}


//fonction de mouvement du hero en fonction de son speedvector
bool Hero::move(){
    extern int W,H;
    //calcul des nouvelle positions
    float x=get_x()+speedvector.x;
    float y =get_y()+speedvector.y;

    //on verifie qu'on ne sort pas de limites du terrain
    if(x>W || x<0 )
    {
        x -= speedvector.x;
    }
    if(y>H || y<0 )
    {
        y -=speedvector.y;
    }

    //affectation de la nouvelle position
    this->set_position(x,y);

    //incrementation de l'age
    inc_age();

    return true;
}
bool Hero::annimation(){
 return true;
}

//permet de modifier le speedvector du hero
//speedvec doit etre normalisé
void Hero::add_speed(vec2 speedvec){
    speedvector+=speedvec*speed;
}
void Hero::setScore(int point)
{
    score=point;
}
int Hero::getScore()
{
    return score;
}
