#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP


#include "hero.h"
#include "enemyping.h"
#include "enemypong.h"
#include "../header/spaceshooter.h"
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>
#include <QSound>

//forward declaration of QLabel


class QLabel;



class render_area : public QWidget
{
    Q_OBJECT
public:

    render_area(QWidget *parent = 0);
    ~render_area();

    void repaint_render(std::list<Drawable_Object*> list);

    int jeu=0;
protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);
//    /** Function called when the mouse is pressed */
//    void mousePressEvent(QMouseEvent *event);
//    /** Function called when the mouse is moved */
//    void mouseMoveEvent(QMouseEvent *event);
//    /** Function called when the button of the mouse is released */
//    void mouseReleaseEvent(QMouseEvent *event);

//    void keyPressEvent(QKeyEvent *event);

//    void keyReleaseEvent(QKeyEvent *event);

private slots:

    /** Function called periodically at constant time interval by a timer */
    //void update_timer();

private: //attributes


//    SpaceShooter *space;
    QPixmap *pixmap;
    //int jeu=0;



//    /** Timer for periodic time iteration */
//    QTimer timer;
//    /** Time accessor */
//    QTime time;
    std::list<Drawable_Object*> buffer;

};

#endif
