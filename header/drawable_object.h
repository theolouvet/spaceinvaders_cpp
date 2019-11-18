#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include <string>
#include <QString>



//Classe abstraite qui contient les element permettant de dessiner un objet dans une render area
class Drawable_Object
{
private:
    //position actuel de l'objet
    float x,y;

    //position initial de l'objet
    float const xini,yini;

//    float teta;

    float scalex,scaley;
  //  QString image;
    // age de l'ennemie sur le plateau en nombre d'iteration
    long long int age;
    QString image;
public:
    //constructeur
    Drawable_Object(float x,float y);
    ~Drawable_Object();
    //permet de definir une position a l'objet
    void set_position(float x,float y);
    void set_image(QString);
    QString getImage();
    void set_scale(float x, float y);
    float get_scalex();
    float get_scaley();
    //accesseurs
    float get_x();
    float get_y();
    float get_xini();
    float get_yini();

    // fonction abstraite imposant a chaque vaisseau de pouvoir
    // se deplacer dans un terrain de dimension WxH
    // renvoie si l'objet est toujours sur le terrein apres son mouvement
    virtual bool move() ;


    //accesseurs et mutateur d'age
    long long int get_age();
    void inc_age();




};

#endif // DRAWABLE_OBJECT_H
