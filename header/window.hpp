
#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include"spaceshooter.h"
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
//forward declaration
namespace Ui{
class MainWindow;
}
class render_area;

/** Declaration of the window class */
class window: public QMainWindow
{
    Q_OBJECT

public:

    window(QWidget *parent=nullptr);
    ~window();

protected:
    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);
private slots:

    void action_quit();
    void affscore(int sc);
    void affvie(int vie);
    void action_jouer();
    void update_timer();
    void choix_theme();
private:

    Ui::MainWindow *ui;
    render_area *render;

    SpaceShooter* jeu;
    /** Timer for periodic time iteration */
    QTimer timer;
    /** Time accessor */
    QTime time;

    int choix;

};

#endif
