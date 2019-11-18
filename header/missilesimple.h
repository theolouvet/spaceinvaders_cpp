#ifndef MISSILESIMPLE_H
#define MISSILESIMPLE_H

#include "../header/vec2.hpp"
#include "../header/missile.h"


//missile enemie de base
class MissileSimple : public Missile
{

private:
    //direction de deplacement du missile
    vec2 direction;
public:
    //constructeur
    MissileSimple(float x, float y);
    //fonction de deplacement
    bool move()override;
};

#endif // MISSILESIMPLE_H
