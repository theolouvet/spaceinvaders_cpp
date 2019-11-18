#ifndef SPACEFOND_H
#define SPACEFOND_H


#include"drawable_object.h"
#include <list>
#include <QString>

class SpaceFond
{

private:
    Drawable_Object * fond1;
    Drawable_Object * fond2;
    int age;
public:
    SpaceFond();
    void move();
    std::list<Drawable_Object *> get_fond();


};

#endif // SPACEFOND_H
