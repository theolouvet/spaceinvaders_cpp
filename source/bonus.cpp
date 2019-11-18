#include "../header/bonus.h"

Bonus::Bonus(float x, float y, int bonustype):Drawable_Object(x,y),bonustype(bonustype)
{

}

bool Bonus::move(){
    extern int W,H;
    long long int age=get_age();
    float x = get_xini();
    float y = get_yini()+age*3;
    this->set_position(x,y);
    inc_age();

    if (x<0||x>W||y>H){
        return false;
    }
    return true;
}
int Bonus::get_bonustype(){
 return bonustype;
}
