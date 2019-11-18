#include "../header/missile.h"


Missile::Missile(float x, float y,int deg,int speed):Drawable_Object(x,y),degat(deg),age(0),speed(speed)
{

}
int Missile::get_degat(){
    return degat;
}

void Missile::inc_age(){
    age++;
}
int Missile::get_age(){
    return age;
}

int Missile::get_speed(){
    return speed;
}
