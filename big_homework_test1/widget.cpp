#include "widget.h"
#include "ui_widget.h"
#include "gacha_1_time.h"
#include "gacha_5_times.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->test1->setText("智力");
//    ui->test2->setText("体力");
//    ui->test3->setText("金钱");
    //this->setFixedSize(700,670);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_BTNgacha_1_clicked()
{
    gacha_1_time* g1t=new gacha_1_time;
    this->hide();
    g1t->show();
//    this->show();
}

void Widget::on_BTNgacha_5_clicked()
{
    gacha_5_times* g5t=new gacha_5_times;
    this->hide();
    g5t->show();
//    this->show();
}


