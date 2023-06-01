#include "gacha_5_times.h"
#include "ui_gacha_5_times.h"
#include "card_properties.h"

gacha_5_times::gacha_5_times(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gacha_5_times)
{
    ui->setupUi(this);
}

gacha_5_times::~gacha_5_times()
{
    delete ui;
}

void gacha_5_times::on_pushButton_2_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}


void gacha_5_times::on_pushButton_4_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}


void gacha_5_times::on_pushButton_3_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}


void gacha_5_times::on_pushButton_5_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}


void gacha_5_times::on_pushButton_6_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}

