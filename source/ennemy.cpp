#include "../header/ennemy.h"


Ennemy::Ennemy(float x,float y,int v):Ship(x,y,v)
{

}

//Permet de definir le nombre de points que donne un ennemi
void Ennemy::setPoint(int point)
{
    this->point=point;
}

//renvoie le nombre de point de l'ennemi
int Ennemy::getPoint(){
    return this->point;
}



