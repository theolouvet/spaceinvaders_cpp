#include "../header/enemypong.h"



EnemyPong::EnemyPong(float x, float y,int theme):Ennemy(x,y,5)
{
    set_theme(theme);
    set_image("image"+QString::number(get_theme())+"/Alien1.gif");
    set_scale(30,30);
    setPoint(30);
}

std::list<Missile*> EnemyPong::gen_missile(){
    std::list<Missile*> res;
    long long int age=get_age();
    float x = get_x();
    float y =get_y();
        if (age%40==0){
            res.push_back(new MissileSimple(x,y));
        }
    return res;
}

bool EnemyPong::move(){

    extern int W,H;

    long long int age=get_age();

    float x = get_xini()+100*cos(2*3.1415*age/100);
    float y = get_yini()+age/2;

    this->set_position(x,y);

    inc_age();

    if (x<0||x>W||y>H){
        return false;
    }
    if(get_theme()==1)
    {
        annimation();
    }
    return true;
}
bool EnemyPong::annimation(){

    if(get_age()%5==0){
        set_image("image1/Alien11.gif");
    }
    if(get_age()%10==0){
        set_image("image1/Alien1.gif");
    }
    return true;

}
