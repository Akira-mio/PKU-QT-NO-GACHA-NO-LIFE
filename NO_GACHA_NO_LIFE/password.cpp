#include "password.h"
#include "ui_password.h"
#include "trueend.h"
#include <QMessageBox>
#include<QDebug>
#include<QTime>
#include<QWidget>
#include<QSoundEffect>
password::password(QString trueending,QMediaPlayer*play,QWidget *parent) :
    QWidget(parent),p(play),
    ui(new Ui::password)
{
    ui->setupUi(this);
    trueend=trueending;
    if (trueend.length()<6) trueend='0'+trueend;
    setWindowTitle(tr("系统接口"));
}

password::~password()
{
    delete ui;
}

void password::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



void password::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text() == trueend){
        qDebug()<<"ok"<<Qt::endl;
        ui->lineEdit->hide();
        ui->label->setText(tr("YOU HAVE OBTAINED THE SYSTEM PERMISSION"));
        ui->label->setWordWrap(1);
        sleep(1000);
        TrueEnd *e=new TrueEnd(p);
        this->close();
        e->show();

        QSoundEffect *soundEffect = new QSoundEffect();
        soundEffect->setSource(QUrl("qrc:/background.wav"));
        soundEffect->setLoopCount(1);
        soundEffect->setVolume(100);
        soundEffect->play();

    }
    else {
        QMessageBox::warning(this,tr("系统警告！"),tr("权限密码输入错误！"),QMessageBox::Ok);
        ui->lineEdit->clear();
    }
}

void password::goto_trueend(){

}
