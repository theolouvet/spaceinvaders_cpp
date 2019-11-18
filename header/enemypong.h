/*Classe Drawable_Object
 * Description:
 *
 * Methodes:
 *
 * Auteur: Lopez Matéo/Louvet Théo
*/
#ifndef ALEXBARAN_H
#define ALEXBARAN_H
#include "ennemy.h"
#include"../header/missilesimple.h"

//ennemie EnemyPong

class EnemyPong : public Ennemy
{
public:
    //constructeur
    EnemyPong(float x, float y,int theme);

    //mouvement
    bool move() override;
    bool annimation() override;
    //generation de missile
    std::list<Missile*> gen_missile() override;
};

#endif // ENEMYPONG_H
