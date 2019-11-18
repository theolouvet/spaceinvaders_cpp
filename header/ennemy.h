#ifndef ENNEMY_H
#define ENNEMY_H
#include "ship.h"

#include <cmath>

//Surement inutile

class Ennemy : public Ship
{
private:
    int point;

public:
    //constructeur
    Ennemy(float x, float y, int vie);
    Ennemy();
    void setPoint(int);
    int getPoint();



};

#endif // ENNEMY_H
