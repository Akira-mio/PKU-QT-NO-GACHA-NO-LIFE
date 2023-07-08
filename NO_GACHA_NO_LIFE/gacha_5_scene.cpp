#include "gacha_5_scene.h"
#include "ui_gacha_5_scene.h"
#include<QPainter>
#include"gacha_5_times.h"
#include<core_algorithm.h>
#include<QMediaPlayer>
gacha_5_scene::gacha_5_scene(Gamer* player,QMediaPlayer*p,QWidget *parent) :
    g5player(player),QWidget(parent),play(p),
    ui(new Ui::gacha_5_scene)
{
    ui->setupUi(this);
}

gacha_5_scene::~gacha_5_scene()
{
    delete ui;
}

void gacha_5_scene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/gacha_scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/pictures/card_background3.png");
    pix.scaled(170,150);
    painter.drawPixmap(23,100,170,150,pix);
    painter.drawPixmap(215,100,170,150,pix);
    painter.drawPixmap(407,100,170,150,pix);
    painter.drawPixmap(105,300,170,150,pix);
    painter.drawPixmap(325,300,170,150,pix);
}

void gacha_5_scene::on_pushButton_clicked()
{
    this->close();

    gacha_5_times* g5t=new gacha_5_times(g5player,play);
    g5t->show();
}

