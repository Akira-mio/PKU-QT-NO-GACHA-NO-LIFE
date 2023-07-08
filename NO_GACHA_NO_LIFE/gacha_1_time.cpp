#include "gacha_1_time.h"
#include "ui_gacha_1_time.h"
#include "card_properties.h"
#include "core_algorithm.h"
#include "widget.h"
#include <QDebug>
#include <qpushbutton.h>
#include<QPainter>
#include<QMediaPlayer>
gacha_1_time::gacha_1_time(Gamer *players,QMediaPlayer*p,QWidget *parent) :
    QWidget(parent),play(p),
    ui(new Ui::gacha_1_time)
{
    ui->setupUi(this);
    ui->goback->hide();
    int cardnum=players->drawACard();//抽到的卡牌编号
    ui->broad_category->setText(players->cardLibrary[cardnum]->name);
    my_player = players;
    cardNum = new int(cardnum);
}

gacha_1_time::~gacha_1_time()
{
    delete ui;
}

void gacha_1_time::on_pushButton_clicked()
{
    if(!ispushed){
    ispushed = true;
    ui->pushButton->hide();
    ui->goback->show();
    card_properties* caprs=new card_properties(my_player,cardNum);

    caprs->setModal(true);
    caprs->show();

    }
}


void gacha_1_time::on_goback_clicked()
{
    Widget* p = new Widget(my_player,play);
    p->show();
    this->close();
}
void gacha_1_time::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/gacha_scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    if(*cardNum>=1&&*cardNum<=5)
    {
        pix.load(":/pictures/card1.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=6&&*cardNum<=7)
    {
        pix.load(":/pictures/card2.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=8&&*cardNum<=12)
    {
        pix.load(":/pictures/card3.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=13&&*cardNum<=14)
    {
        pix.load(":/pictures/card4.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=15&&*cardNum<=20)
    {
        pix.load(":/pictures/card5.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=21&&*cardNum<=25)
    {
        pix.load(":/pictures/card6.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else if(*cardNum>=101&&*cardNum<=106)
    {
        pix.load(":/pictures/card7.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }
    else
    {
        pix.load(":/pictures/cardDIY.jpg");
        pix.scaled(300,300);
        painter.drawPixmap(150,120,300,300,pix);
    }


}

