#ifndef SPACESHOOTER_H
#define SPACESHOOTER_H


//Classe permmetant de crée et simuler une instance de jeu

#include<list>
#include "spacefond.h"
//ennemies
#include "../header/enemyping.h"
#include "../header/enemypong.h"
//hero
#include "../header/hero.h"
//bonus
#include "bonusvie.h"
#include "bonusbouclier.h"

#include"bouclier.h"

class SpaceShooter
{

private:

    //liste des ennemis et de leurs missiles
    std::list<Ennemy*> enemies;
    std::list<Missile*> enemymissile;

    //liste des bonus attrapable
    std::list<Bonus*> bonuslist;


    //Hero et ses missiles
    Hero* hero;

    std::list<Missile*> missile;
    //liste des boucliers du hero
    std::list<Bouclier*> boucliers;

    //buffer contenant tout les objets a dessiner
    std::list<Drawable_Object*> render_buffer;

    //fond
    SpaceFond * fond;
    int theme;



public:


    //constructeur
    SpaceShooter(int W, int H);

    //Initisialise une nouvelle partie
    void initialisation();

    //effectue la simulation de la partie
    void iteration();

    //Gestion des ennemies:

    // ajout d'un ennemie dans la simulation
    void add_enemy(Ennemy* enemy);
    // ajout d'une liste d'ennemie dans la simulation
    void add_enemies(std::list<Ennemy*> enemies);
    // ajout d'un missile dans la simulation
    void add_enemymissile(Missile* missile);
    // ajout d'une liste de missile dans la simulation
    void add_enemymissiles(std::list<Missile*> missiles);
    // permet de modifier la direction de deplacement du hero
    void add_hero_speed(vec2 speed);
    //permet de savoir si un obj touche un ennemi
    //supprime l'ennemi touché
    bool touche_ennemi(Drawable_Object *obj);

    void add_bonus(Bonus* bonus);
    //Gestion du hero

    //initialise le hero
    void init_hero();
    // ajout d'un missile dans la simulation
    void add_missile(Missile* missile);
    // ajout d'une liste de missile dans la simulation
    void add_missiles(std::list<Missile*> missiles);
    //permet de savoir si un obj touche le hero
    bool touche_hero(Drawable_Object *obj);
    int getScore();
    int getVie();
    int get_theme();
    void set_theme(int theme);
    // ajout d'un boucier dans la simulation
    void add_bouclier(Bouclier* bouc);
    // ajout d'une liste de bouclier dans la simulation
    void add_boucliers(std::list<Bouclier*> bouc);

    //gestion du buffer d'affichage
    void gen_render_buffer();
    std::list<Drawable_Object*> get_render_buffer();
    bool touche_bouclier(Drawable_Object* mis);

    int diagenemie(int y);

};

#endif // SPACESHOOTER_H
