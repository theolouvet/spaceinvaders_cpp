#include "../header/bouclier.h"
#include <math.h>

Bouclier::Bouclier(int ageini):Drawable_Object(-10,-10),ageini(ageini)
{
    set_image("imagebonus/bouclier.gif");
    set_scale(30,30);
}
bool Bouclier::move(){
    extern int herox,heroy;

    float x = herox +20*cos(2*3.1415*(get_age()+ageini)/100);
    float y = heroy +20*sin(2*3.1415*(get_age()+ageini)/100);

    set_position(x,y);
    inc_age();

    return true;

}
