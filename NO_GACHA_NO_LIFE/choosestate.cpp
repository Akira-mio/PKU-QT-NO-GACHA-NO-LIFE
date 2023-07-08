#include "choosestate.h"
#include "ui_choosestate.h"
#include "core_algorithm.h"
#include <QMessageBox>>

choosestate::choosestate(int num,Gamer* g,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosestate),
    ply(g),
    amount(num)
{
    ui->setupUi(this);
    if (num==10||num==-10) ui->label->setText("请选择你要增减的属性：");
    if (num==100) ui->label->setText("请选择你要将三种属性变为和哪一种一样：");
}

choosestate::~choosestate()
{
    delete ui;
}

void choosestate::updateUI(){
    emit sendupdateUI(ply);
}

void choosestate::on_intelligence_clicked()
{
    if (amount==10||amount==-10) {
        ply->player->intellegence+=amount;
        ply->player->money-=500;
        QMessageBox::information(this,"提示","购买成功！");
    }
    if (amount==100){
        ply->player->income=ply->player->strength=ply->player->intellegence;
        ply->player->money-=5000;
        QMessageBox::information(this,"提示","购买成功！");
    }
    sendupdateUI(ply);
    delete this;
}





void choosestate::on_strength_clicked()
{
    if (amount==10||amount==-10) {
        ply->player->strength+=amount;
        ply->player->money-=500;
        QMessageBox::information(this,"提示","购买成功！");
    }
    if (amount==100){
        ply->player->intellegence=ply->player->income=ply->player->strength;
        ply->player->money-=5000;
        QMessageBox::information(this,"提示","购买成功！");
    }
    sendupdateUI(ply);
    delete this;
}


void choosestate::on_income_clicked()
{
    if (amount==10||amount==-10) {
        ply->player->income+=amount;
        ply->player->money-=500;
        QMessageBox::information(this,"提示","购买成功！");
    }
    if (amount==100){
        ply->player->strength=ply->player->intellegence=ply->player->income;
        ply->player->money-=5000;
        QMessageBox::information(this,"提示","购买成功！");
    }
    sendupdateUI(ply);
    delete this;
}

