
#include "../header/window.hpp"

#include "../header/render_area.hpp"
#include "ui_mainwindow.h"
#include "../header/hero.h"
#include <iostream>
#include <string>

window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area),
      timer(),
      time()
{
    ui->setupUi(this);
    ui->layout_scene->addWidget(render);
   // render->setup_bounce_number(ui->bounces_number);


    //std::cout<<"hey"<<std::endl;
    //Connection with signals

    connect(ui->quit,SIGNAL(clicked()),this,SLOT(action_quit()));

    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(action_jouer()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(choix_theme()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(choix_theme()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(choix_theme()));

    choix=1;
    jeu = NULL;
    affscore(0);
    affvie(5);

}
window::~window()
{}
void window::affscore(int sc)
{

    ui->scorelabel->setText("<html><h1><strong>score\n"+QString::number(sc)+"</strong></h1></html>");
}
void window::affvie(int vie)
{

    ui->vielabel->setText("<html><h2><strong>Vie:\n"+QString::number(vie)+"</strong></h2></html>");
}
void window::keyPressEvent(QKeyEvent *event){
    //std::cout << this->size()<<"hey!\n";

    switch(event->key())
        {
            case Qt::Key_Left:
                jeu->add_hero_speed(vec2(-1,0));
                break;

            case Qt::Key_Right:
                jeu->add_hero_speed(vec2(1,0));
                break;

            case Qt::Key_Down:
                jeu->add_hero_speed(vec2(0,1));
                break;

            case Qt::Key_Up:
                jeu->add_hero_speed(vec2(0,-1));
                break;

        }
}
void window::keyReleaseEvent(QKeyEvent *event){

    switch(event->key())
        {
            case Qt::Key_Left:
                jeu->add_hero_speed(vec2(1,0));
                break;

            case Qt::Key_Right:
                jeu->add_hero_speed(vec2(-1,0));
                break;

            case Qt::Key_Down:
                jeu->add_hero_speed(vec2(0,-1));
                break;

            case Qt::Key_Up:
                jeu->add_hero_speed(vec2(0,1));
                break;
        }


}
void window::choix_theme(){
    if(/*render->jeu==0*/1)
    {
        if(ui->radioButton_2->isChecked()){
            choix=2;
        }
        else if(ui->radioButton_3->isChecked()){
            choix=3;
        }
        else{
            choix=1;

        }
    }
    this->setFocus();
}

void window::action_quit()
{
    close();
}
void window::action_jouer(){
    setFocus();
    if(jeu == NULL){
        jeu = new SpaceShooter(render->width(),render->height());
        jeu->set_theme(choix);
    }

    if(render->jeu==0){
    timer.start(30);
    std::cout<<choix<<std::endl;
    jeu->set_theme(choix);
    jeu->initialisation();

    //delete jeu;

    //jeu = new SpaceShooter(render->width(),render->height());

    render->jeu=1;
    }
    else{
        timer.stop();
        render->jeu=0;

    }
}
void window::update_timer(){
    //setFocus();

    jeu->iteration();

    affscore(jeu->getScore());
    affvie(jeu->getVie());
    if(jeu->getVie()<=0){
        render->jeu=0;
        timer.stop();
    }
    render->repaint_render(jeu->get_render_buffer());
}
