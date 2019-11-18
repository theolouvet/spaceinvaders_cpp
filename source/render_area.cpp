
#include "../header/render_area.hpp"

#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

#include <list>


render_area::render_area(QWidget *parent)
    :QWidget(parent),pixmap(new QPixmap())

{



}

render_area::~render_area()
{

}


void render_area::repaint_render(std::list<Drawable_Object *> list){
    //le buffer des éléments à afficher est actualisé
    buffer=list;


    repaint();

}

void render_area::paintEvent(QPaintEvent*)
    {
        QPainter painter(this);

        //si le jeu est lancé
        if(jeu==1){
            // parcour du buffer des elements à afficher
            for(auto obj:buffer){
                pixmap->load(obj->getImage());//recuperation de l'image
                *pixmap = pixmap->scaled(obj->get_scalex(),obj->get_scaley());//et des dimensions
                painter.drawPixmap(obj->get_x()-obj->get_scalex()/2,obj->get_y()-obj->get_scaley()/2,*pixmap);//affichage
            }
        }
        // si le jeu n'est pas lancé affichage du fond
        else{

            pixmap->load("Ciel.jpg");
           *pixmap = pixmap->scaled(1500,1500);
           painter.drawPixmap(0,0,*pixmap);
        }

}





