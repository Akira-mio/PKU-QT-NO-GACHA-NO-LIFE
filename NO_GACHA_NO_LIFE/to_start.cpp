#include "to_start.h"
#include "ui_to_start.h"
#include "widget.h"
#include "core_algorithm.h"
#include "setting.h"
#include <QDialog>
#include "random.h"
#include <QMessageBox>
#include<QEvent>
#include"diycard.h"
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
#include<QSoundEffect>
#include<QThread>
#define cout qDebug()

to_start::to_start(QMediaPlayer* p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::to_start)
{
    ui->setupUi(this);
    play=p;
    this->setFixedSize(this->size());

    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/to_start_background.jpg");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    //this->setAutoFillBackground(true);
    this->setPalette(pa);
}

to_start::~to_start()
{
    delete ui;
}

void to_start::on_newgame_clicked()
{
    //ui->newgame->setStyleSheet("color: rgb(255, 255, 0);");
    QSoundEffect a;
//    QThread thread1;
//    a.moveToThread(&thread1);
//    thread1.start();
    //a.setSource(QUrl("qrc:/dingdong_1.wav"));
    //a.setLoopCount(1);
    //a.setVolume(0.5);
    //a.play();qDebug()<<"ok";
    setting* s = new setting(play);
    this->close();
    s->setModal(1);
    s->show();
    play->stop();
    play->setSource(QUrl("qrc:/starsky.mp3"));
    play->play();
}


void to_start::on_loaddata_clicked()
{
    //ui->loaddata->setStyleSheet("color: rgb(255, 255, 0);");
    //QSoundEffect b;
    //b.setSource(QUrl("qrc:/dingdong.wav"));
    //b.setLoopCount(1);
    //b.setVolume(100.0);
    //b.play();
    Gamer* players= new Gamer;
    QFile file4(":/data/savedata.txt");
    if (file4.open(QIODevice::ReadOnly|QIODevice::Text)){
    QTextStream cin4(&file4);
    cin4>>players->player->intellegence>>players->player->strength>>players->player->income>>players->player->money>>players->date>>players->date>>players->trueending>>players->stopbad>>players->stopgood;
    cout<<players->player->intellegence<<" "<<players->player->strength<<" "<<players->player->income<<" "<<players->player->money<<" "<<players->date<<players->trueending<<players->stopbad<<players->stopgood;
    file4.close();
    players->gameStart();
    players->dayStart();
    players->setLuck();
    players->putCard();
    this->close();
    play->stop();
    play->setSource(QUrl("qrc:/starsky.mp3"));
    play->play();
    players->randomEvent();
    Widget *w=new Widget(players,play);
    if(1){

        random*ran = new random(players);

        ran->setParent(w);
        ran->setWindowFlags(Qt::Dialog);
        ran->show();
    }
    w->show();
    }
    else QMessageBox::critical(this,"警告","还没有存档！");

}








void to_start::on_diyc_clicked()
{
    //QSoundEffect c;
    //c.setSource(QUrl("qrc:/dingdong.wav"));
    //c.setLoopCount(1);
    //c.setVolume(100.0);
    //c.play();
    diycard* diy=new diycard(play);
    this->close();
    diy->show();
}

