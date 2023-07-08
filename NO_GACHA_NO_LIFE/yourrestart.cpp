#include "yourrestart.h"
#include "ui_yourrestart.h"
#include "QString"
#include <QMessageBox>

yourrestart::yourrestart(Gamer* g,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yourrestart),
    ply(g)
{
    ui->setupUi(this);
    ui->total->setText(QString::number(g->player->income+g->player->intellegence+g->player->strength));
    totalnum=g->player->income+g->player->intellegence+g->player->strength;
}

yourrestart::~yourrestart()
{
    delete ui;
}
#if 0
void yourrestart::on_buttonBox_accepted()
{
    if ((ui->income->value()+ui->intelligence->value()+ui->strength->value())==totalnum&&ui->income->value()>0&&ui->income->value()<100&&ui->intelligence->value()>0&&ui->intelligence->value()<100&&ui->strength->value()>0&&ui->strength->value()<100){
        ply->player->income=ui->income->value();
        ply->player->intellegence=ui->intelligence->value();
        ply->player->strength=ui->strength->value();
        delete this;
    }
    else{
        QMessageBox::critical(this,"警告","请检查是否正确分配");
    }
}

void yourrestart::on_buttonBox_rejected()
{
    delete this;
}
#endif

void yourrestart::updateUI(){
    emit sendupdateUI(ply);
}

void yourrestart::on_sure_clicked()
{
    if ((ui->income->value()+ui->intelligence->value()+ui->strength->value())==totalnum&&ui->income->value()>0&&ui->income->value()<100&&ui->intelligence->value()>0&&ui->intelligence->value()<100&&ui->strength->value()>0&&ui->strength->value()<100){
        ply->player->income=ui->income->value();
        ply->player->intellegence=ui->intelligence->value();
        ply->player->strength=ui->strength->value();
        ply->player->money-=4000;
        QMessageBox::information(this,"提示","购买成功！");
        sendupdateUI(ply);
        delete this;
    }
    else{
        QMessageBox::critical(this,"警告","请检查是否正确分配");
    }
}

