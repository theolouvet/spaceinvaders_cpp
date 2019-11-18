#include "../header/spacefond.h"

SpaceFond::SpaceFond():age(0)
{
    fond1 = new Drawable_Object(0,0);
    fond1->set_scale(1500,1500);
    fond1->set_image("Ciel.jpg");
    fond2 = new Drawable_Object(0,1500);
    fond2->set_scale(1500,1500);
    fond2->set_image("Ciel.jpg");
}


void SpaceFond::move(){
    age ++ ;
    fond1->set_position(0,age);
    fond2->set_position(0,age-1500);
    if (age == 1500){
        age = 0;
    }

}
std::list<Drawable_Object *> SpaceFond::get_fond(){

    std::list<Drawable_Object *> res;
    res.push_back(fond1);
    res.push_back(fond2);
    return res;

}
