#include "setting.h"
#include "ui_setting.h"
#include "course.h"
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
setting::setting(QMediaPlayer* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    play=p;
    this->setStyleSheet("color:rgb(255,255,255)");

    this->setFixedSize(this->size());
    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/to_start_background.jpg");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    //this->setAutoFillBackground(true);
    this->setPalette(pa);

    ui->settings->setText(QString("<html><body>"
                            "<p>你是北京大学信息科学技术学院的一名普通学生。你没有什么不良嗜好，除了一项——抽卡游戏。</p>"
                            "<p>在缪尔赛思池子的最后一天，你准备梭哈攒下的十几万合成玉。</p>"
                            "<p>几十抽下去，一道火光闪现在你的眼前，“要出了！”你惊喜地期待着缪缪的上岛。</p>"
                            "<p>“我此行不代表梅兰德基金会……”，顿时，你由狂喜转为无限的悲伤。“没事，还有抽数。”你安慰自己。</p>"
                            "<p>然而，无论抽多少次，你的池子里好像没有别的六星，除了这个中坚术士。</p>"
                            "<p>270抽后，合成玉与原石终于见底，可缪尔赛思似乎在与你捉迷藏。“博士，再抽几发就能把我娶回家哦~~</p>"
                            "<p>“忍不了！你进入充值界面，准备打开蓝绿修改器氪上一单。“怎么没钱了，我的生活费呢？”</p>"
                            "<p>原来，不久之前的草神池，你的生活费已被消耗殆尽。万策尽矣！~”</p>"
                            "<p>“抽卡之神啊，请再给我一些抽数吧！”你呼喊道。</p>"
                            "<p>“你想要更多的抽卡次数？”银铃般的声音在你耳边呢喃。</p>"
                            "<p>“我想要！”</p>"
                            "<p>“那就跟我来另一个世界吧~在这里，有着无尽的抽卡次数，无限的人生可能，唯一你所需要的，只是那么一丁点小小的运气~”</p>"
                            "<p>一道白光出现在你的眼前，你穿越了。</p>"
                            "</body></html>"  ) );
    ui->settings->setWordWrap(1);
}


setting::~setting()
{
    delete ui;
}

void setting::on_goto_course_clicked()
{
    course* c = new course(play);
    this->close();
    c->setModal(1);
    c->show();
}

