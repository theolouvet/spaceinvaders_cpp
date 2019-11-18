#include "../header/ship.h"

//on construit l'objet avec sa position initial et son nombre de vies
Ship::Ship(float x, float y, int v):Drawable_Object(x,y),vie(v),theme(1)
{
}

//permet de modifier la vie
void Ship::set_vie(int v){
    vie = v;
}

//retourne le nombre de vie du vaisseau
int Ship::get_vie(){
    return vie;
}

void Ship::set_theme(int choix){
    theme=choix;
}
int Ship::get_theme(){
    return theme;
}




