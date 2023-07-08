#include "card_properties.h"
#include "ui_card_properties.h"
#include"core_algorithm.h"
#include<QStringAlgorithms>
#include<QString>
#include<QDebug>

card_properties::card_properties(Gamer*players,int *cardnum,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::card_properties)
{
    ui->setupUi(this);
    players->chosenCard(*cardnum);
    QString income=QString::number(players->cardLibrary[*cardnum]->dincome);
    QString intellegence=QString::number(players->cardLibrary[*cardnum]->dintellegence);
    QString strength=QString::number(players->cardLibrary[*cardnum]->dstrength);
    QString money=QString::number(players->cardLibrary[*cardnum]->dmoney);
    QString move=QString::number(players->cardLibrary[*cardnum]->dmove);
    if(players->cardLibrary[*cardnum]->dincome>=0)income='+'+income;
    if(players->cardLibrary[*cardnum]->dintellegence>=0)intellegence='+'+intellegence;
    if(players->cardLibrary[*cardnum]->dstrength>=0)strength='+'+strength;
    if(players->cardLibrary[*cardnum]->dmoney>=0)money='+'+money;
    if(players->cardLibrary[*cardnum]->dincome>=0)move='+'+move;

    ui->details->setText(QString("<html><body>"
                                 "<p>%1</p>"
                                 "<p>income%2</p>"
                                 "<p>intellegence%3</p>"
                                 "<p>strength%4</p>"
                                 "<p>money%5</p>"
                                 "<p>move%6</p>"
                                 "</body></html>").arg(players->cardLibrary[*cardnum]->description).arg(income)
                                                  .arg(intellegence).arg(strength)
                                                  .arg(money).arg(move));
    ui->details->setWordWrap(true);
}

card_properties::~card_properties()
{

    delete ui;
}

void card_properties::on_pushbutton_clicked()
{
    this->close();
}

