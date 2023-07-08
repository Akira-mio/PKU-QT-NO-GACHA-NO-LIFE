#include "cutscene.h"
#include "ui_cutscene.h"
#include "widget.h"
#include "core_algorithm.h"
#include "theend.h"
#include "random.h"
#include <QString>
#include<QStringAlgorithms>
#include<QMessageBox>
#include"to_start.h"
#include<QDebug>

cutscene::cutscene(Gamer*players,QMediaPlayer*play,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cutscene)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    p=play;
    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/cutscene_background2.png");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    this->setAutoFillBackground(true);
    this->setPalette(pa);

    ui->label->setText(QString("<html><body>"
                               "<p>美好充实的一天过去了，你觉得该休息了，躺上床后马上就进入了梦乡...</p>"
                               "<p>Day %1 -> Day %2</p>"
                               "</body></html>").arg(QString::number(players->date)).arg(QString::number(players->date+1)));
    my_player = players;
}

cutscene::~cutscene()
{
    delete ui;
}

void cutscene::on_goto_nextday_clicked()
{
    my_player->dayStart();
    my_player->setLuck();
    my_player->putCard();
    qDebug()<<my_player->player->intellegence;
    qDebug()<<my_player->player->income;
    qDebug()<<my_player->player->strength;
    qDebug()<<my_player->gameEnd;
    if(my_player->gameEnd){
        TheEnd* te =new TheEnd(my_player,p);
        this->close();
        te->show();
        return ;
    }
    my_player->randomEvent();
    Widget *w = new Widget(my_player,p);
    //connect(p,SIGNAL(sendend()),p,SLOT(gameover()));
    this->close();


    if(1){
      random*ran = new random(my_player);

      ran->setParent(w);
      ran->setWindowFlags(Qt::Dialog);
      ran->setModal(1);
      connect(ran,SIGNAL(sendupdateUI(Gamer*)),w,SLOT(updateUI(Gamer*)));
      ran->show();
    }
    w->show();

}



void cutscene::on_save_data_clicked()
{
     QMessageBox::information(this,"提示","已存档");
    QFile file3(":/data/savedata.txt");
    file3.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream cout1(&file3);
    cout1<<my_player->player->intellegence<<" "<<my_player->player->strength<<" "<<my_player->player->income<<" "<<my_player->player->money<<" "<<my_player->date<<" "<<my_player->trueending<<" "<<my_player->stopbad<<" "<<my_player->stopgood;
    file3.close();
}


void cutscene::on_backtomenu_clicked()
{

    auto reply=QMessageBox::information(this,"提示","确定要回到主菜单吗？请确保你已存档！",QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes){
        this->close();
      p->stop();
      p->setSource(QUrl("qrc:/This game.mp3"));
      p->play();
      to_start *pp = new to_start(p);
        pp->show();

    }
}

