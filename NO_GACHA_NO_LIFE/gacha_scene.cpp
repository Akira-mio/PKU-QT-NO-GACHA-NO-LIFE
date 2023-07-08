#include "gacha_scene.h"
#include "ui_gacha_scene.h"
#include<QPainter>
#include"gacha_1_time.h"
#include<core_algorithm.h>
#include<QMediaPlayer>

gacha_scene::gacha_scene(Gamer* player,QMediaPlayer*p,QWidget *parent) :
    gplayer(player), QWidget(parent),play(p),
    ui(new Ui::gacha_scene)
{
    ui->setupUi(this);

}

void gacha_scene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/gacha_scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/pictures/card_background3.png");
    pix.scaled(300,250);
    painter.drawPixmap(150,125,300,250,pix);
}

gacha_scene::~gacha_scene()
{
    delete ui;
}

void gacha_scene::on_pushButton_clicked()
{
    this->close();
    gacha_1_time* g1t=new gacha_1_time(gplayer,play);
    connect(g1t,SIGNAL(sendsignal()),this,SLOT(reshow(QMediaPlayer*)));

    g1t->show();
}

