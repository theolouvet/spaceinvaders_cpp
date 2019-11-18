#include "../header/missilesimple.h"

MissileSimple::MissileSimple(float x, float y ):Missile(x,y,1,7),direction(0,1)
{
    set_image("image1/misen.gif");
    set_scale(20,20);
}

bool MissileSimple::move(){

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

