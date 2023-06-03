#include "cutscene.h"
#include "ui_cutscene.h"


cutscene::cutscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cutscene)
{
    ui->setupUi(this);
}

cutscene::~cutscene()
{
    delete ui;
}
