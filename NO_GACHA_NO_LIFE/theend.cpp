#include "theend.h"
#include "ui_theend.h"
#include "core_algorithm.h"
#include "to_start.h"
#include "password.h"
#include <QStringAlgorithms>
#include <QDebug>
#include <QPainter>
#include"to_start.h"
#include<QMediaPlayer>
TheEnd::TheEnd(Gamer*players,QMediaPlayer*play,QWidget *parent) :
    endplayer(players),QDialog(parent),p(play),
    ui(new Ui::TheEnd)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    setWindowTitle(tr("大结局"));
    QString str,str123,str456;
    trueend=players->trueending*10101;
//    ui->label->setText(str);
//    ui->label->setWordWrap(1);
//    ui->gameover->hide();
//    ui->new_game->hide();
//    sendButton = new QPushButton("……", this);
//                                           sendButton->setGeometry(9,237,382,24);
//                                 connect(sendButton, &QPushButton::clicked, this, &TheEnd::goto_password);

    str123="“恭喜你哇，你在这个世界混的不错嘛。你做的很棒，让我看到了人类无限的可能性。看来是我小看人类了，我得考虑加强测试的难度了。”一瞬间，你回到了原本的世界，你的账号中凭空出现了30抽。你用这30抽井出了缪缪，达成了夙愿。";
    str456="“糟糕，你在这个世界怎么混成这个样子。果然人类不过只是人类啊。我得降低测试难度了，小白鼠精神崩坏什么的，我可是会很困扰的。”一瞬间，你回到了原本的世界，你的账号中凭空出现了30抽。你用这30抽井出了缪缪，达成了夙愿。";
    if (players->player->income==players->trueending&&players->player->intellegence==players->trueending&&players->player->strength==players->trueending&&players->trueending!=0){
        //真结局
    str="又一天结束了，还要在这个世界度过几天呢？这个世界究竟是虚拟的还是真实的？如此思考着，你像往常一样进入了梦乡……";

    ui->label->setStyleSheet("color:rgb(255,255,255);");
    ui->label->setText(str);
    ui->label->setWordWrap(1);
    ui->gameover->hide();
    ui->new_game->hide();
    sendButton = new QPushButton("……", this);
    sendButton->setGeometry(110,380,380,30);
    //sendButton->setFlat(true);

    connect(sendButton, &QPushButton::clicked, this, &TheEnd::goto_password);
    }
    else{
    if (players->player->intellegence>=100){
        str="彩虹色的绩点已经无法满足你了，你参加了ACM竞赛，本科生科研，全部取得了不错的成绩。\n\n";
        str+=str123;
    }
    if (players->player->intellegence<=0){
        str="你看着自己的绩点页面五花八门的字母组合，悲从心来。再这样下去，真的要退学了啊！ICS，AI什么的，不懂，搞不明白，全都不知所云！\n\n";
        str+=str456;
    }
    if (players->player->income>=100){
        str="尚在大学的你，攒下了人生中的第一桶金。你用这笔钱创业，高超的商业头脑让你的事业越做越大，你成为了名副其实的富哥（姐）。\n\n";
        str+=str123;
    }
    if (players->player->income<=0){
        str="怎么又没钱了！急着给新角色氪金的你加入了各种兼职群，不料却陷入电信诈骗的漩涡，血本无归。好在警察叔叔追回了一部分损失，但你作为电信诈骗的典型案例被公开处刑，在同学间社会性死亡。\n\n";
        str+=str456;
    }
    if (players->player->strength>=100){
        str="经过不断的锻炼，你的身体素质已经达到了大学生的顶尖水平。体测什么的自然不是话下，而在各种校级运动比赛中，你也总能拔得头筹。\n\n";
        str+=str123;
    }
    if (players->player->strength<=0){
        str="常年的信科作息逐渐摧毁了你的健康与精神。你胡子越来越多，头发却越来越少。你成了名副其实的家里蹲，每天在泡面与游戏中虚度自己的青春。\n\n";
        str+=str456;
    }
    //if (players->date>20){
    //    str="太久了";
    //}
    ui->label->setText(str);
    ui->label->setWordWrap(1);
}

}

TheEnd::~TheEnd()
{
    delete ui;
}

void TheEnd::on_new_game_clicked()
{
    p->stop();
    p->setSource(QUrl("qrc:/This game.mp3"));
    p->play();
    to_start *pp = new to_start(p);
    pp->show();
    this->close();
}


void TheEnd::on_gameover_clicked()
{
    this->close();
}

void TheEnd::goto_password(){
    p->stop();
    this->close();
    qDebug()<<trueend<<Qt::endl;
    password *P= new password(QString::number(trueend),p);
    P->show();
}

void TheEnd::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    if(endplayer->player->income==endplayer->trueending&&endplayer->player->intellegence==endplayer->trueending&&endplayer->player->strength==endplayer->trueending&&endplayer->trueending!=0)
    {
        pix.load(":/pictures/cutscene_background2.png");
        pix.scaled(600,420);
        painter.drawPixmap(0,0,600,420,pix);
    }
    else if(endplayer->player->intellegence>=100||endplayer->player->income>=100||endplayer->player->strength>=100)
    {
        pix.load(":/pictures/good_ending.jpg");
        pix.scaled(250,200);
        painter.drawPixmap(175,150,250,200,pix);

    }
    else if(endplayer->player->intellegence<=0||endplayer->player->income<=0||endplayer->player->strength<=0)
    {
        pix.load(":/pictures/bad_ending.jpg");
        pix.scaled(156,180);
        painter.drawPixmap(222,150,156,180,pix);
    }

}
