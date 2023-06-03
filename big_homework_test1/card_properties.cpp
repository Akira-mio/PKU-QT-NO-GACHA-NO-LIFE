#include "card_properties.h"
#include "ui_card_properties.h"


card_properties::card_properties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::card_properties)
{
    ui->setupUi(this);
}

card_properties::~card_properties()
{

    delete ui;
}

void card_properties::on_pushButton_clicked()
{
    this->close();
}

