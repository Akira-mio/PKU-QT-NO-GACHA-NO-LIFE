#include "gacha_1_time.h"
#include "ui_gacha_1_time.h"
#include "card_properties.h"

gacha_1_time::gacha_1_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gacha_1_time)
{
    ui->setupUi(this);
}

gacha_1_time::~gacha_1_time()
{
    delete ui;
}

void gacha_1_time::on_pushButton_clicked()
{
    card_properties* caprs=new card_properties;
    caprs->setModal(true);
    caprs->show();
}

