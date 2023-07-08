#include "widget.h"
#include "ui_widget.h"
#include "gacha_1_time.h"
#include "gacha_5_times.h"
#include "core_algorithm.h"
#include "cutscene.h"
#include "theend.h"
#include "news.h"
#include "random.h"
#include "shop.h"
#include <QString>
#include <QStringAlgorithms>
#include <QDebug>
#include <QMessageBox>
#include "gacha_scene.h"
#include "gacha_5_scene.h"
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>

Widget::Widget(Gamer *players,QMediaPlayer*p,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(800,500);
    //BTN->setMouseTracking(true);
    play=p;
    ui->setupUi(this);
    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/main_background.jpg");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    //this->setAutoFillBackground(true);
    this->setPalette(pa);

    if(players->player->move<=0){
        ui->BTNgacha_1->hide();
        ui->BTNgacha_5->hide();
    }

    //players->player->intellegence=200;//强制结局

    ui->LBintelligence_->setText(QString::number(players->player->intellegence));
    ui->LBpower_->setText(QString::number(players->player->strength));
    ui->LBmoney_->setText(QString::number(players->player->money));
    ui->LBincome_->setText(QString::number(players->player->income));
    ui->LBmove_->setText(QString::number(players->player->move));
    ui->LBcurrent_day_->setText(QString::number(players->date));

    //点击事件
        qDebug() << "income:" << players->player->income ;
        qDebug() << "intellegence:" << players->player->intellegence;
        qDebug() <<"strength:" << players->player->strength ;
        qDebug() << "money:" << players->player->money;
        qDebug() << "move:" << players->player->move;
#if 0
        if(players->judgeEnd()){}
#endif
        my_player = players;
    //connect(ui->BTNnext_day,&QPushButton::clicked,this,);
//        QIcon icon(":/pictures/opensound.jpg");
//        ui->soundbutton->setIcon(QIcon::fromTheme(":/pictures/opensound.jpg")); qDebug()<<"ok";
//        ui->soundbutton->setIconSize(QSize(20,20));
        if(my_player->music){
        ui->soundbutton->setText(tr("音乐：开"));
        }else
        ui->soundbutton->setText(tr("音乐：关"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateUI(Gamer*p){
    ui->LBintelligence_->setText(QString::number(p->player->intellegence));
    ui->LBpower_->setText(QString::number(p->player->strength));
    ui->LBmoney_->setText(QString::number(p->player->money));
    ui->LBincome_->setText(QString::number(p->player->income));
    ui->LBmove_->setText(QString::number(p->player->move));
    ui->LBcurrent_day_->setText(QString::number(p->date));
    if (my_player->player->move>0){
        ui->BTNgacha_1->show();
        ui->BTNgacha_5->show();
    }
}

void Widget::on_BTNgacha_1_clicked()
{
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    this->hide();

    gacha_scene * gc=new gacha_scene(my_player,play);
    gc->show();

    //gacha_1_time* g1t=new gacha_1_time(my_player);
    //connect(g1t,SIGNAL(sendsignal()),this,SLOT(reshow()));

    //g1t->show();
//    this->show();
}

void Widget::on_BTNgacha_5_clicked()
{
    if(my_player->player->money<1000){
        QMessageBox::critical(this,"警告","您的金钱不足");
        return;
    }
    if(my_player->player->move<=0){
        QMessageBox::critical(this,"警告","您的行动力不足");
        return;
    }
    this->hide();
    //if(my_player->player->money<1000)return;//弹窗提示
   //connect(g5t,SIGNAL(sendsignal()),this,SLOT(reshow()));

    gacha_5_scene * gc5=new gacha_5_scene(my_player,play);
    gc5->show();
    //gacha_5_times* g5t=new gacha_5_times(my_player);
    //g5t->show();
//    this->show();
}



void Widget::on_BTNnext_day_clicked()
{
    if (my_player->player->income==my_player->trueending&&my_player->player->intellegence==my_player->trueending&&my_player->player->strength==my_player->trueending&&my_player->trueending!=0){
        //真结局
        gameEnd=1;
    }else
        if(my_player->judgeEnd()){
            gameEnd=1;
            if (my_player->stopgood==1){
                if (my_player->player->intellegence>=100){
                    my_player->player->intellegence=80;
                    my_player->stopgood=0;
                    gameEnd=0;
                }
                if (my_player->player->strength>=100){
                    my_player->player->strength=80;
                    my_player->stopgood=0;
                    gameEnd=0;
                }
                if (my_player->player->income>=100){
                    my_player->player->income=80;
                    my_player->stopgood=0;
                    gameEnd=0;
                }
            }
            if (my_player->stopbad==1){
                if (my_player->player->intellegence<=0){
                    my_player->player->intellegence=20;
                    my_player->stopbad=0;
                    gameEnd=0;
                }
                if (my_player->player->strength<=0){
                    my_player->player->strength=20;
                    my_player->stopbad=0;
                    gameEnd=0;
                }
                if (my_player->player->income<=0){
                    my_player->player->income=20;
                    my_player->stopbad=0;
                    gameEnd=0;
                }
            }
        }
    if(gameEnd){
        my_player->gameEnd=1;
        emit sendend();
        qDebug()<<"ok";
    }
    else{
        my_player->gameEnd=0;
        emit sendend();
    }

    cutscene* p = new cutscene(my_player,play);
    this->close();
    p->show();

}


void Widget::on_shop_clicked()
{
    shop* p=new shop(my_player);
    p->setParent(this);
    p->setWindowFlags(Qt::Dialog);
    connect(p,SIGNAL(sendupdateUI(Gamer*)),this,SLOT(updateUI(Gamer*)));
    p->setWindowFlags(p->windowFlags() |Qt::Dialog);
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}


void Widget::on_soundbutton_clicked()
{
    if(my_player->music){
        ui->soundbutton->setText(tr("音乐：关"));
        play->stop();qDebug()<<"ok";
        flag=1;
        my_player->music=0;
    }
    else{
        ui->soundbutton->setText(tr("音乐：开"));
        play->play();
        flag=0;
         my_player->music=1;
    }
}

