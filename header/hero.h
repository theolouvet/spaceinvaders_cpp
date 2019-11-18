#ifndef HERO_H
#define HERO_H

#include"ship.h"
#include"vec2.hpp"
#include"../header/missilehero.h"
#include <QPixmap>
#include <QString>
//classe du personnage controler par le joueur,
//le joueur a 5 vie
class Hero : public Ship
{

private:
    //vecteur vitesse du hero
    vec2 speedvector;

    //vitesse du hero
    int speed;
    int score=0;


public:
    //constructeur
    Hero(float x, float y);
  //  virtual typeid(Hero);
    //initialisation du hero
    void init();

    //generation de missile
    std::list<Missile*> gen_missile() override;

    //fonction de deplacement du hero
    bool move() override;
    bool annimation() override;
    void setScore(int);
    int getScore();
    //modification du vecteur vitesse du hero
    void add_speed(vec2 speed);
     //QPixmap *pixmap;

};

#endif // HERO_H
