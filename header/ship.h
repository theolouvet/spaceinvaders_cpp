#ifndef SHIP_H
#define SHIP_H
#include "drawable_object.h"
#include"../header/missile.h"
#include<list>
#include <QString>



//classe abstraite permmetant de gerer un vaisseau
class Ship : public Drawable_Object
{
private :
    //vie du vaisseau
    int vie;
    int theme;
public:
    //constructeur
    Ship(float x,float y,int vie);



    virtual bool annimation()=0;
    //fonction de generations de missile
    virtual std::list<Missile*> gen_missile() =0;

    //mutateur et accesseur pour la variable vie
    void set_vie(int v);
    int get_vie();
    void set_theme(int choix);
    int get_theme();



};

#endif // SHIP_H
