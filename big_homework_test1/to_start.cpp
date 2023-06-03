#include "to_start.h"
#include "ui_to_start.h"
#include "widget.h"



to_start::to_start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::to_start)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

to_start::~to_start()
{
    delete ui;
}

void to_start::on_pushButton_clicked()
{
    Widget *w=new Widget;
    this->close();
    w->show();
}

