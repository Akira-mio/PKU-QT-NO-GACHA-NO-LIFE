#include "shop.h"
#include "ui_shop.h"
#include "character.h"
#include "choosestate.h"
#include "core_algorithm.h"
#include "yourrestart.h"
#include <random>
#include <algorithm>
#include<QMessageBox>
#include<QDebug>
#include<QPainter>

shop::shop(Gamer* g,QWidget *parent) :
    QWidget(parent),
    gamer(g),
    ui(new Ui::shop)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

shop::~shop()
{
    delete ui;
}

void shop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/shop_background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/pictures/niunai2.png");
    pix.scaled(100,100);
    painter.drawPixmap(80,20,100,100,pix);

    pix.load(":/pictures/xuezhangbiji2.png");
    pix.scaled(100,100);
    painter.drawPixmap(260,20,100,100,pix);

    pix.load(":/pictures/bukaopubiji2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(440,20,100,100,pix);

    pix.load(":/pictures/buwendingyaoji2.png");
    pix.scaled(100,100);
    painter.drawPixmap(620,20,100,100,pix);

    pix.load(":/pictures/wendingyaoji2.png");
    pix.scaled(100,100);
    painter.drawPixmap(80,180,100,100,pix);

    pix.load(":/pictures/mima2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(260,180,100,100,pix);

    pix.load(":/pictures/yajuejinzhuan2.png");
    pix.scaled(100,100);
    painter.drawPixmap(440,180,100,100,pix);

    pix.load(":/pictures/caipiao2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(620,180,100,100,pix);

    pix.load(":/pictures/shiguangzhimo2.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(125,340,100,100,pix);

    pix.load(":/pictures/shiguangzhimo3.jpg");
    pix.scaled(100,100);
    painter.drawPixmap(350,340,100,100,pix);

    pix.load(":/pictures/xiaojingzi2.png");
    pix.scaled(100,100);
    painter.drawPixmap(575,340,100,100,pix);

}

void shop::updateUI(){
    emit sendupdateUI(gamer);
}

void shop::coffee(Gamer* g){
    if (g->player->money>=300){
        g->player->move++;
        g->player->money-=300;
        QMessageBox::information(this,"提示","购买成功！");
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::seniors_note(Gamer* g){
    if (g->player->money>=500){
    choosestate* cst=new choosestate(10,g);
    cst->setWindowFlags(cst->windowFlags() |Qt::Dialog);
    cst->setWindowModality(Qt::ApplicationModal);
    cst->show();
    connect(cst,SIGNAL(sendupdateUI(Gamer*)),this,SLOT(updateUI()));
    //sendupdateUI(gamer);
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::treehole_note(Gamer* g){
    if (g->player->money>=300){
    choosestate* cst=new choosestate(-10,g);
    cst->setWindowFlags(cst->windowFlags() |Qt::Dialog);
    cst->setWindowModality(Qt::ApplicationModal);
    cst->show();
    connect(cst,SIGNAL(sendupdateUI(Gamer*)),this,SLOT(updateUI()));
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::random_restart(Gamer* g){
    if (g->player->money>=1000){
    g->player->money-=1000;
    int sum=g->player->income+g->player->intellegence+g->player->strength;
    int cut1=0,cut2=0;
    int a=0,b=0,c=0;
    while (cut1==cut2||a==0||b==0||c==0||a>=100||b>=100||c>=100){
        cut1=rand()&(sum/2);
        cut2=rand()&(sum/2)+sum/2;
        if (cut1==cut2) continue;
        if (cut1>cut2) std::swap(cut1,cut2);
        a=cut1;
        b=cut2-cut1;
        c=sum-cut2;
    }
    g->player->income=a;
    g->player->intellegence=b;
    g->player->strength=c;
    //做个弹窗显示一下变化后的结果
    QMessageBox::information(this,"提示","购买成功！");
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::your_restart(Gamer* g){
    if (g->player->money>=4000){
    yourrestart* yrs=new yourrestart(g);
    connect(yrs,SIGNAL(sendupdateUI(Gamer*)),this,SLOT(updateUI()));
    yrs->exec();
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::secret_password(Gamer* g){
    if (g->player->money>=1500){
    g->player->money-=1500;
    int n=rand()%99+1;
    QMessageBox::information(this,"提示",QString::number(n));
    g->trueending=n;
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::stop_bad(Gamer* g){
    if (g->player->money>=1500){
    g->player->money-=1500;
    QMessageBox::information(this,"提示","购买成功");
    g->stopbad=1;
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::stop_good(Gamer* g){
    if (g->player->money>=1500){
    g->player->money-=1500;
    QMessageBox::information(this,"提示","购买成功");
    g->stopgood=1;
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::fourleaf(Gamer* g){
    if (g->player->money>=800){
    g->player->money-=800;
    QMessageBox::information(this,"提示","购买成功");
    g->player->luck=8;
    g->putCard();
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::makesame(Gamer* g){
    if (g->player->money>=5000){
    choosestate* cst=new choosestate(100,g);
    cst->setWindowFlags(cst->windowFlags() |Qt::Dialog);
    cst->setWindowModality(Qt::ApplicationModal);
    cst->show();
    connect(cst,SIGNAL(sendupdateUI(Gamer*)),this,SLOT(updateUI()));
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}
void shop::lottery(Gamer* g){
    if (g->player->money>=200){
    g->player->money-=200;
    int m=rand()%400;
    g->player->money+=m;
    QMessageBox::information(this,"提示","彩票开奖，您获得了金钱"+QString::number(m));
    }
    else QMessageBox::information(this,"提示","您的金钱不足！");
}


void shop::on_coffee_clicked()
{
    coffee(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_goodnote_clicked()
{
    seniors_note(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    //sendupdateUI(gamer);
}


void shop::on_badnote_clicked()
{
    treehole_note(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    //sendupdateUI(gamer);
}


void shop::on_random_clicked()
{
    random_restart(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_your_clicked()
{
    your_restart(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    //sendupdateUI(gamer);
}


void shop::on_password_clicked()
{
    secret_password(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_fourleaves_clicked()
{
    fourleaf(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_stopgood_clicked()
{
    stop_good(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_stopbad_clicked()
{
    stop_bad(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    sendupdateUI(gamer);
}


void shop::on_same_clicked()
{
    makesame(gamer);
    cout<<"**********";
    cout<<gamer->player->intellegence;
    cout<<gamer->player->strength;
    cout<<gamer->player->income;
    cout<<gamer->player->money;
    cout<<gamer->player->move;
    //sendupdateUI(gamer);
}


void shop::on_lottery_clicked()
{
    lottery(gamer);
    sendupdateUI(gamer);
}

