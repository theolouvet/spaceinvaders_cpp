/*Classe Drawable_Object
 * Des
*/
#include "../header/drawable_object.h"

//on construit l'objet avec sa position initiale
Drawable_Object::Drawable_Object(float px, float py):
x(px),y(py),xini(px),yini(py),age(0)
{

}
Drawable_Object::~Drawable_Object(){}

//defini une position courante pour l'objet
void Drawable_Object::set_position(float px,float py){
    x=px;
    y=py;
    return;
}
void Drawable_Object::set_image(QString im ){
    image=im;
}

//renvoie la position courante suivant x
float Drawable_Object::get_x(){
    return x;
}
//renvoie la position courante suivant y
float Drawable_Object::get_y(){
    return y;
}
//renvoie la position initiale suivant x
float Drawable_Object::get_xini(){
    return xini;
}
//renvoie la position initiale suivant y
float Drawable_Object::get_yini(){
    return yini;
}
float Drawable_Object::get_scalex(){
    return scalex;
}
float Drawable_Object::get_scaley(){
    return scaley;
}
void Drawable_Object::set_scale(float x, float y){
    scalex=x;
    scaley=y;
}

bool Drawable_Object::move(){
    return true;
}

//retourne l'age du vaisseau
long long int Drawable_Object::get_age(){

    return age;
}

//increment l'age de l'objet
void Drawable_Object::inc_age(){
    age+=1;
}
 QString Drawable_Object::getImage(){
     return image;
 }
