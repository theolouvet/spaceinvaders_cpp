#ifndef LUDOVENET_H
#define LUDOVENET_H
#include "ennemy.h"
#include "../header/missilesimple.h"
#include <QPixmap>


//enemi EnemyPing
class EnemyPing : public Ennemy
{

public:
    //constructeur
    EnemyPing(float x, float y,int theme);
    //fonction de mouvement
    bool move() override;
    bool annimation() override;
    //generation de missile
    std::list<Missile*> gen_missile() override;

};

#endif // EnemyPing
