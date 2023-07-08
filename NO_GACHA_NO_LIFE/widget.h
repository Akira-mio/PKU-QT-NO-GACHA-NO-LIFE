#ifndef WIDGET_H
#define WIDGET_H
#include "core_algorithm.h"
#include "theend.h"
#include <QWidget>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
#pragma once
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
     Widget(Gamer*player = nullptr,QMediaPlayer*p=nullptr,QWidget *parent = nullptr);
    ~Widget();
signals:
     void sendend();
private slots:
    void on_BTNgacha_1_clicked();

    void on_BTNgacha_5_clicked();

    //void on_BTNnextday_clicked(Gamer*players);

    void on_BTNnext_day_clicked();
    void reshow(QMediaPlayer*p){
        play=p;
        this->show();}
//    void gameover(){
//        TheEnd* te =new TheEnd(my_player);
//        this->close();
//        te->show();
//    }
    void on_shop_clicked();

    void updateUI(Gamer*p);
    void on_soundbutton_clicked();

private:
    Ui::Widget *ui;
    Gamer *my_player;
    bool gameEnd=0;
    bool flag=0;
    QMediaPlayer*play;
};
#endif // WIDGET_H
