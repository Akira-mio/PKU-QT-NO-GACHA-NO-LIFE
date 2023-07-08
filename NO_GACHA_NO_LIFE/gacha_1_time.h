#ifndef GACHA_1_TIME_H
#define GACHA_1_TIME_H

#include "core_algorithm.h"
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
namespace Ui {
class gacha_1_time;
}

class gacha_1_time : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_1_time(Gamer* player,QMediaPlayer*p,QWidget *parent = nullptr);
    ~gacha_1_time();
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();
    void on_goback_clicked();

signals:
    void sendsignal();

private:
    Ui::gacha_1_time *ui;
    Gamer*my_player;
    int *cardNum;
    bool ispushed=0;
    QMediaPlayer*play;
};

#endif // GACHA_1_TIME_H
