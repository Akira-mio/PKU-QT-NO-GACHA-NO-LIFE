#include "random.h"
#include "ui_random.h"
#include "news.h"
#include "core_algorithm.h"
#include<windows.h>
#include<QWidget>
#include<QSoundEffect>

random::random(Gamer*players,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::random),
    g(players)
{
    ui->setupUi(this);

    this->setStyleSheet("color:rgb(255,255,255)");

    this->setFixedSize(this->size());
    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/news_background3.jpg");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    this->setAutoFillBackground(true);
    this->setPalette(pa);

    news* today_event = *players->today_event;
    n=today_event;
    QString str;
    str="中平";
    switch (players->player->luck-players->player->intellegence/25) {
        case 0:str= "大凶" ; break;
        case 1:str=  "凶" ; break;
        case 2:str=  "中平" ; break;
        case 3:str=  "吉" ; break;
        case 4:str=  "大吉" ; break;
    }
        QSoundEffect *soundEffect = new QSoundEffect();
        soundEffect->setSource(QUrl("qrc:/inform.wav"));
        soundEffect->setLoopCount(1);
        soundEffect->setVolume(100);
        soundEffect->play();

#if 0
    ui->label->setText(QString("<html><body>"
                               "<p>今日运势：%7</p>"
                                 "<p>%8</p>"
                                 "<p>%1</p>"
                                 "<p>income+%2</p>"
                                 "<p>intellegence+%3</p>"
                                 "<p>strength+%4</p>"
                                 "<p>money+%5</p>"
                                 "<p>move+%6</p>"
                                 "</body></html>").arg(today_event->description).arg(QString::number(today_event->dincome))
                                                  .arg(QString::number(today_event->dintellegence)).arg(QString::number(today_event->dstrength))
                                                  .arg(QString::number(today_event->dmoney)).arg(QString::number(today_event->dmove))
                                                  .arg(str).arg(today_event->name));
    ui->label->setWordWrap(true);
#endif


    ui->label->setText(QString("<html><body>"
                               "<p>今日运势：%1</p>"
                               "<p>今日随机事件：%2</p>"
                               "</body></html>").arg(str).arg(today_event->name));
    ui->choice1->setText(today_event->option1);
    ui->choice2->setText(today_event->option2);
    ui->choice3->setText(today_event->option3);
    ui->label->setWordWrap(true);

}


random::~random()
{
    delete ui;
}

void random::setui1(){
    QString income=QString::number(n->dincome1);
    QString intellegence=QString::number(n->dintellegence1);
    QString strength=QString::number(n->dstrength1);
    QString money=QString::number(n->dmoney1);
    QString move=QString::number(n->dmove1);
    if(n->dincome1>=0)income='+'+income;
    if(n->dintellegence1>=0)intellegence='+'+intellegence;
    if(n->dstrength1>=0)strength='+'+strength;
    if(n->dmoney1>=0)money='+'+money;
    if(n->dincome1>=0)move='+'+move;

    ui->label->setText(QString("<html><body>"
                               "<p>%1</p>"
                               "<p>income%2</p>"
                               "<p>intellegence%3</p>"
                               "<p>strength%4</p>"
                               "<p>money%5</p>"
                               "<p>move%6</p>"
                               "</body></html>").arg(n->option1).arg(income)
                           .arg(intellegence).arg(strength)
                           .arg(money).arg(move)
                           );
    ui->label->setWordWrap(true);

}
void random::setui2(){
    QString income=QString::number(n->dincome2);
    QString intellegence=QString::number(n->dintellegence2);
    QString strength=QString::number(n->dstrength2);
    QString money=QString::number(n->dmoney2);
    QString move=QString::number(n->dmove2);
    if(n->dincome2>=0)income='+'+income;
    if(n->dintellegence2>=0)intellegence='+'+intellegence;
    if(n->dstrength2>=0)strength='+'+strength;
    if(n->dmoney2>=0)money='+'+money;
    if(n->dincome2>=0)move='+'+move;

    ui->label->setText(QString("<html><body>"
                               "<p>%1</p>"
                               "<p>income%2</p>"
                               "<p>intellegence%3</p>"
                               "<p>strength%4</p>"
                               "<p>money%5</p>"
                               "<p>move%6</p>"
                               "</body></html>").arg(n->option2).arg(income)
                           .arg(intellegence).arg(strength)
                           .arg(money).arg(move)
                       );
    ui->label->setWordWrap(true);

}
void random::setui3(){
    QString income=QString::number(n->dincome3);
    QString intellegence=QString::number(n->dintellegence3);
    QString strength=QString::number(n->dstrength3);
    QString money=QString::number(n->dmoney3);
    QString move=QString::number(n->dmove3);
    if(n->dincome3>=0)income='+'+income;
    if(n->dintellegence3>=0)intellegence='+'+intellegence;
    if(n->dstrength3>=0)strength='+'+strength;
    if(n->dmoney3>=0)money='+'+money;
    if(n->dincome3>=0)move='+'+move;

    ui->label->setText(QString("<html><body>"
                               "<p>%1</p>"
                               "<p>income%2</p>"
                               "<p>intellegence%3</p>"
                               "<p>strength%4</p>"
                               "<p>money%5</p>"
                               "<p>move%6</p>"
                               "</body></html>").arg(n->option3).arg(income)
                           .arg(intellegence).arg(strength)
                           .arg(money).arg(move)
                       );
    ui->label->setWordWrap(true);

}

void random::updateUI(){
    emit sendupdateUI(g);
}

void random::on_pushButton_clicked()
{
    this->close();
}

void random::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void random::on_choice1_clicked()
{
    ui->choice1->hide();
    ui->choice2->hide();
    ui->choice3->hide();
    setui1();
    g->player->income+=n->dincome1;
    g->player->intellegence+=n->dintellegence1;
    g->player->strength+=n->dstrength1;
    g->player->money+=n->dmoney1;
    g->player->move+=n->dmove1;
    sendupdateUI(g);
    //Sleep(3000);
    //this->close();
}


void random::on_choice2_clicked()
{
    ui->choice1->hide();
    ui->choice2->hide();
    ui->choice3->hide();
    setui2();
    g->player->income+=n->dincome2;
    g->player->intellegence+=n->dintellegence2;
    g->player->strength+=n->dstrength2;
    g->player->money+=n->dmoney2;
    g->player->move+=n->dmove2;
    sendupdateUI(g);
    //Sleep(3000);
    //this->close();
}


void random::on_choice3_clicked()
{
    ui->choice1->hide();
    ui->choice2->hide();
    ui->choice3->hide();
    setui3();
    g->player->income+=n->dincome3;
    g->player->intellegence+=n->dintellegence3;
    g->player->strength+=n->dstrength3;
    g->player->money+=n->dmoney3;
    g->player->move+=n->dmove3;
    sendupdateUI(g);
    //Sleep(3000);
    //this->close();

}

