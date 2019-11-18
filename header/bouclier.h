#ifndef BOUCLIER_H
#define BOUCLIER_H


#include "drawable_object.h"
class Bouclier : public Drawable_Object
{

private:

    int ageini;

public:
    Bouclier(int ageini);

    bool move() override;
};

#endif // BOUCLIER_H
