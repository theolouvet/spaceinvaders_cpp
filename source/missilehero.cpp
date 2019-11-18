#include "../header/missilehero.h"

MissileHero::MissileHero(float x, float y, vec2 direction, int theme):Missile(x,y,1,20),direction(direction)
{
    set_image("image"+QString::number(theme)+"/mis.png");
    set_scale(20,20);
}

bool MissileHero::move(){

    extern int H,W;


    int age = get_age();
    float speed=get_speed();
    float x = get_x();
    float y = get_y();

    x=get_xini()+direction.x*age*speed;
    y=get_yini()+direction.y*age*speed;

    set_position(x,y);
    inc_age();

    if(x>W || x<0 || y>H || y<0  )
    {
        return false;
    }

    return true;
}


