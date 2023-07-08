#include "shoppushbutton.h"
#include<QWidget>
#include<QPushButton>
#include<QSoundEffect>

shoppushbutton::shoppushbutton(QWidget *parent)
    : QPushButton{parent}
{

}

void shoppushbutton::enterEvent(QEnterEvent * event)
{
    this->setStyleSheet("color: rgb(0, 0, 255);");
    //QDebug() <<1 ;
};

void shoppushbutton::leaveEvent(QEvent * event)
{
    this->setStyleSheet("color: rgb(255, 255, 255);");

};
void shoppushbutton::mouseReleaseEvent(QMouseEvent *event){
    QSoundEffect *soundEffect = new QSoundEffect();
    soundEffect->setSource(QUrl("qrc:/buy.wav"));
    soundEffect->setLoopCount(1);
    soundEffect->setVolume(100);
    soundEffect->play();
    return QPushButton::mouseReleaseEvent(event);
}
