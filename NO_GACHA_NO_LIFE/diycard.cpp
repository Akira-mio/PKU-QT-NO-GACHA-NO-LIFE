#include "diycard.h"
#include "ui_diycard.h"
#include <QTableWidget>
#include<QTableWidgetItem>
#include <QPushButton>
#include <QDebug>
#include <QStringList>
#include <QString>
#include<QRegularExpression>
#include<QFile>
#include<QMessageBox>
#include "to_start.h"
diycard::diycard(QMediaPlayer*p,QWidget *parent) :
    QWidget(parent),music(p),
    ui(new Ui::diycard)
{
    ui->setupUi(this);
    QFile file("mycard.txt");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream cin(&file);
        for (int i=0;i<20;i++){
            int num;
            cin>>num;
            if (num==999) {
                file.close();
                return;
            }
            for (int j=0;j<8;j++){
                QString temp;
                cin>>temp;
                if (temp!="*s*t*o*p*") ui->table->setItem(i,j,new QTableWidgetItem(temp));
            }
        }
    }

}
diycard::~diycard()
{
    delete ui;
}
void diycard::delete_space(){
    for (int i=0;i<20;i++)
        for (int j=0;j<8;j++){
            qDebug()<<i<<j;
            if (ui->table->item(i,j)!=nullptr) content[i][j]=ui->table->item(i,j)->text();
            else {
                endline=i;
                return;
            }
            qDebug()<<i<<j;
            content[i][j].remove(QRegularExpression("\\s"));
            qDebug()<<i<<j;
            if (content[i][j]==""){
                endline=i;
                return;
            }
            qDebug()<<i<<j;
        }
}
bool diycard::check_num(){
    for (int i=0;i<endline;i++)
        for (int j=2;j<8;j++){
            bool ok;
            if (!content[i][j].toInt(&ok)) return false;
        }
    return true;
}
void diycard::save(){
    QFile file(":/data/mycard.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream cout(&file);
    for (int i=0;i<endline;i++){
        cout<<200+i;
        for (int j=0;j<8;j++){
            cout<<" "<<content[i][j];
        }
        cout<<Qt::endl;
    }
    cout<<999;
}

void diycard::on_save_clicked()
{
    delete_space();
    qDebug()<<1;
    if (check_num()) save();
    else QMessageBox::critical(this,"警告","请检查3-8列已填写部分是否全为数值！");
    this->close();
    to_start *s=new to_start(music);
    s->show();
}


void diycard::on_cancel_clicked()
{
    this->close();
    to_start *s=new to_start(music);
    s->show();
}

