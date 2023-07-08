#include "gacha_5_times.h"
#include "ui_gacha_5_times.h"
#include "card_properties.h"
#include "cutscene.h"
#include "core_algorithm.h"
#include"widget.h"
#include <vector>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QString>
#include<QPainter>
#include<QMediaPlayer>
gacha_5_times::gacha_5_times(Gamer*players,QMediaPlayer*p,QWidget *parent) :
    QWidget(parent),play(p),
    ui(new Ui::gacha_5_times)
{
    ui->setupUi(this);
    //players->player->money-=1000;
   players->player->money-=1000;
    std::vector<int> cardNum;
    for (int i=0;i<5;i++)
        cardNum.push_back(players->drawACard());
    int *take = cardNum.data();
    ui->label_1->setText(players->cardLibrary[*take]->name);    ui->label_1->setWordWrap(1);
    ui->label_2->setText(players->cardLibrary[*(++take)]->name);ui->label_2->setWordWrap(1);
    ui->label_3->setText(players->cardLibrary[*(++take)]->name);ui->label_3->setWordWrap(1);
    ui->label_4->setText(players->cardLibrary[*(++take)]->name);ui->label_4->setWordWrap(1);
    ui->label_5->setText(players->cardLibrary[*(++take)]->name);ui->label_5->setWordWrap(1);
    ui->move->setText(QString::number(players->player->move));
    my_player = players;
    cardnum =  new std::vector<int>(cardNum);
}

gacha_5_times::~gacha_5_times()
{
    delete ui;
}

void gacha_5_times::on_pushButton_1_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    if(!ispushed[0]){
        ispushed[0]=true;
    int *tmp = cardnum->data();
    card_properties* caprs=new card_properties(my_player,tmp);
    caprs->setModal(true);
    caprs->show();
    ui->pushButton_1->hide();
    ui->move->setText(QString::number(my_player->player->move));
}
}

void gacha_5_times::on_pushButton_2_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    if(!ispushed[1]){
        ispushed[1]=true;
     int *tmp = cardnum->data();
     tmp++;
    card_properties* caprs=new card_properties(my_player,tmp);
    caprs->setModal(true);
    caprs->show();
    ui->pushButton_2->hide();
    ui->move->setText(QString::number(my_player->player->move));
}
}

void gacha_5_times::on_pushButton_3_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    if(!ispushed[2]){
        ispushed[2]=true;
     int *tmp = cardnum->data();
     tmp+=2;
    card_properties* caprs=new card_properties(my_player,tmp);
    caprs->setModal(true);
    caprs->show();
    ui->pushButton_3->hide();
    ui->move->setText(QString::number(my_player->player->move));
}
}

void gacha_5_times::on_pushButton_4_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    if(!ispushed[3]){
        ispushed[3]=true;
    int *tmp = cardnum->data();
    tmp+=3;
    card_properties* caprs=new card_properties(my_player,tmp);
    caprs->setModal(true);
    caprs->show();
    ui->pushButton_4->hide();
    ui->move->setText(QString::number(my_player->player->move));
}
}

void gacha_5_times::on_pushButton_5_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    if(!ispushed[4]){
        ispushed[4]=true;
    int *tmp = cardnum->data();
    tmp+=4;
    card_properties* caprs=new card_properties(my_player,tmp);
    caprs->setModal(true);
    caprs->show();
    ui->pushButton_5->hide();
    ui->move->setText(QString::number(my_player->player->move));
}
}

void gacha_5_times::on_goto_widget_clicked()
{
    //emit sendsignal();
    Widget* p = new Widget(my_player,play);
    p->show();
    this->close();
}
void gacha_5_times::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/gacha_scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    int *temp=cardnum->data();

    if(*temp>=1&&*temp<=5)
    {
    pix.load(":/pictures/card1.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=6&&*temp<=7)
    {
    pix.load(":/pictures/card2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=8&&*temp<=12)
    {
    pix.load(":/pictures/card3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=13&&*temp<=14)
    {
    pix.load(":/pictures/card4.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=15&&*temp<=20)
    {
    pix.load(":/pictures/card5.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=21&&*temp<=25)
    {
    pix.load(":/pictures/card6.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else if(*temp>=101&&*temp<=106)
    {
    pix.load(":/pictures/card7.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }
    else
    {
    pix.load(":/pictures/cardDIY.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(10,150,100,100,pix);
    }

    temp++;

    if(*temp>=1&&*temp<=5)
    {
    pix.load(":/pictures/card1.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=6&&*temp<=7)
    {
    pix.load(":/pictures/card2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=8&&*temp<=12)
    {
    pix.load(":/pictures/card3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=13&&*temp<=14)
    {
    pix.load(":/pictures/card4.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=15&&*temp<=20)
    {
    pix.load(":/pictures/card5.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=21&&*temp<=25)
    {
    pix.load(":/pictures/card6.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else if(*temp>=101&&*temp<=106)
    {
    pix.load(":/pictures/card7.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }
    else
    {
    pix.load(":/pictures/cardDIY.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(130,150,100,100,pix);
    }

    temp++;

    if(*temp>=1&&*temp<=5)
    {
    pix.load(":/pictures/card1.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=6&&*temp<=7)
    {
    pix.load(":/pictures/card2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=8&&*temp<=12)
    {
    pix.load(":/pictures/card3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=13&&*temp<=14)
    {
    pix.load(":/pictures/card4.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=15&&*temp<=20)
    {
    pix.load(":/pictures/card5.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=21&&*temp<=25)
    {
    pix.load(":/pictures/card6.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else if(*temp>=101&&*temp<=106)
    {
    pix.load(":/pictures/card7.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }
    else
    {
    pix.load(":/pictures/cardDIY.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(250,150,100,100,pix);
    }

    temp++;

    if(*temp>=1&&*temp<=5)
    {
    pix.load(":/pictures/card1.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=6&&*temp<=7)
    {
    pix.load(":/pictures/card2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=8&&*temp<=12)
    {
    pix.load(":/pictures/card3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=13&&*temp<=14)
    {
    pix.load(":/pictures/card4.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=15&&*temp<=20)
    {
    pix.load(":/pictures/card5.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=21&&*temp<=25)
    {
    pix.load(":/pictures/card6.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else if(*temp>=101&&*temp<=106)
    {
    pix.load(":/pictures/card7.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }
    else
    {
    pix.load(":/pictures/cardDIY.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(370,150,100,100,pix);
    }

    temp++;

    if(*temp>=1&&*temp<=5)
    {
    pix.load(":/pictures/card1.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=6&&*temp<=7)
    {
    pix.load(":/pictures/card2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=8&&*temp<=12)
    {
    pix.load(":/pictures/card3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=13&&*temp<=14)
    {
    pix.load(":/pictures/card4.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=15&&*temp<=20)
    {
    pix.load(":/pictures/card5.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=21&&*temp<=25)
    {
    pix.load(":/pictures/card6.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else if(*temp>=101&&*temp<=106)
    {
    pix.load(":/pictures/card7.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }
    else
    {
    pix.load(":/pictures/cardDIY.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(490,150,100,100,pix);
    }



}

