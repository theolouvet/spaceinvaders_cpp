#ifndef BONUS_H
#define BONUS_H
#include <string>
#include "../header/drawable_object.h"
class Bonus : public Drawable_Object
{
private:
    int bonustype;

public:
    Bonus(float x, float y, int bonustype);
    bool move() override;
    int get_bonustype();

};

#endif // BONUS_H
