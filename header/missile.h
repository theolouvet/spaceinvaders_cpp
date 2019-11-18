#ifndef MISSILE_H
#define MISSILE_H
#include"../header/drawable_object.h"
#include "../header/missile.h"



//classe abstraite permettant de gerer un missile
class Missile : public Drawable_Object
{

private:
    //degat du missile
    int degat;
    //age du missile
    int age;
    //vitesse du missile
    int speed;
public:
    //constructeur
    Missile(float x,float y,int deg,int speed);

//    //fonction de deplacment du missile
//    virtual bool move(float W, float H)=0;

    //mutateur et accesseur de l'age
    void inc_age();
    int get_age();

    //Accesseurs
    int get_degat();
    int get_speed();


};

#endif // MISSILE_H
