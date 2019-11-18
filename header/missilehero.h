#ifndef MISSILEHERO_H
#define MISSILEHERO_H
#include"../header/vec2.hpp"
#include"../header/missile.h"
#include <QPixmap>

//missile de base du hero
class MissileHero : public Missile
{

private:
    //direction de deplacement du missile
    vec2 direction;
public:
    //constructeur
    MissileHero(float x, float y,vec2 direction,int theme);
    //fonction de deplacement
    bool move()override;
   // QPixmap *pixmap;
};

#endif // MISSILEHERO_H
