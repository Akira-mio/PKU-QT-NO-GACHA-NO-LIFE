#include "mypushbutton.h"
#include<QWidget>
#include<QPushButton>
#include<QSoundEffect>

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{

}

void MyPushButton::enterEvent(QEnterEvent * event)
{
    this->setStyleSheet("color: rgb(255, 255, 0);");

    //QDebug() <<1 ;
};

void MyPushButton::leaveEvent(QEvent * event)
{
    this->setStyleSheet("color: rgb(255, 255, 255);");

};
void MyPushButton::mouseReleaseEvent(QMouseEvent *event){
    QSoundEffect *soundEffect = new QSoundEffect();
    soundEffect->setSource(QUrl("qrc:/dingdong.wav"));
    soundEffect->setLoopCount(1);
    soundEffect->setVolume(100);
    soundEffect->play();
    return QPushButton::mouseReleaseEvent(event);
}
