#include "../header/enemyping.h"
#include <QPixmap>
EnemyPing::EnemyPing(float x, float y,int theme):Ennemy(x,y,3)
{
    set_theme(theme);

  set_image("image"+QString::number(get_theme())+"/Alien2.gif");
  set_scale(35,35);
  setPoint(20);
}


std::list<Missile*> EnemyPing::gen_missile(){
    std::list<Missile*> res;
    long long int age=get_age();
    float x = get_x();
    float y =get_y();
        if (age%50==0){
            res.push_back(new MissileSimple(x,y));

        }

    return res;
}

bool EnemyPing::move(){
    extern int W,H;

    long long int age=get_age();

    float x = get_xini()+20*cos(2*3.1415*age/50);
    float y = get_yini()+20*sin(2*3.1415*age/50)+age;

    this->set_position(x,y);
    inc_age();



    if (x<0||x>W||y>H){
        return  false;
    }
    if(get_theme()==1)
    {
    annimation();
     }
    return true;
}
bool EnemyPing::annimation(){
    if(get_age()%5==0){
        set_image("image1/Alien22.gif");
    }
    if(get_age()%10==0){
        set_image("image1/Alien2.gif");
    }

    return true;
}
