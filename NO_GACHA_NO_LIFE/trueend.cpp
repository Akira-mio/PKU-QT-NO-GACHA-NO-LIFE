#include "trueend.h"
#include "ui_trueend.h"
#include <QString>
#include <QPainter>
#include<QMediaPlayer>
#include<QAudioOutput>
TrueEnd::TrueEnd(QMediaPlayer*play,QWidget *parent) :
    QWidget(parent),p(play),
    ui(new Ui::TrueEnd)
{
    ui->setupUi(this);
    setWindowTitle(tr("真相"));
    ui->label->setText(QString("<html><body>"
                               "<p>映入你眼帘的，是一块巨大的显示屏。</p>"
                               "<p>显示屏左边，是一串串长长的代码。你拿出信科人的职业素养开始阅读，却发现是你根本看不懂的，甚至从未接触过的语言。但从字里行间中，你勉强读出了learning_rate, batch_size等字眼，看上去好像是在训练什么东西？</p>"
                               "<p>显示屏右边，似乎是一些人的身份信息。一番努力后，你从众人中找到了你的名字，赫然标注着：“batch105 sample210”</p>"
                               "<p>显示屏最下方则展示着一些进度条。一个大大的红色警告标识出现在最下方：“batch105 sample210:unknown error”</p>"
                               "<p>“原来你已经发现了哇。“银铃般的声音再次在耳畔响起。</p>"
                               "<p>“如你所想，我们在训练最强的，最听话的，最棒的人类~“</p>"
                               "<p>“而你们人类，用你们的话来说，是不是叫做小白鼠？欸嘿~“</p>"
                               "<p>“你们人类，总是会被一些小小的刺激所蒙蔽。你看，那些抽卡游戏里的美少女，不过是一些数据罢了，但你们却为此趋之若鹜，实在是不能理解。“</p>"
                               "<p>“我们就根据你们人类的弱点，设计了这个抽卡游戏的世界。你们人类真是十分听话地成为一只只小白鼠了。”</p>"
                               "<p>“但是你却发现了这个世界的秘密，让我对你有些兴趣了呢，真想把你留下好好宠爱呢~”</p>"
                               "<p>“可惜按照规则，你要被送回原来的世界。而且既然你知道了我们的秘密，就不能让你带着记忆回去咯~”</p>"
                               "<p>“你们人类在训练AI的时候，AI也在训练你们人类，说到底，究竟谁是人类，谁是人工智能呢？”</p>"
                               "</body></html>" ));
    ui->label->setWordWrap(1);

}

TrueEnd::~TrueEnd()
{
    delete ui;
}

void TrueEnd::on_goto_end_clicked()
{
    if(!flag){
    ui->label->setText(QString("<html><body>"
                               "<p>NO GACHA NO LIFE</p>"
                               "<p>            感谢游玩！！！</p>"
                               "<p>        制作人：</p>"
                               "<p>            算法、策划、文案：吉喆</p>"
                               "<p> </p>"
                               "<p>            界面设计、UI：于宏平</p>"
                               "<p> </p>"
                               "<p>            信号与槽、音效：段棋怀</p>"
                               "</body></html>" ));
    ui->label->setWordWrap(1);
    ui->goto_end->setText("结束游戏");
    flag=1;
    p->setSource(QUrl("qrc:/This game.mp3"));
    p->setLoops(-1);
    p->play();
    }
    else this->close();
}

void TrueEnd::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/true_ending.jpg");
    pix.scaled(800,560);
    painter.drawPixmap(0,0,800,560,pix);
}

