#ifndef GACHA_5_TIMES_H
#define GACHA_5_TIMES_H

#include "core_algorithm.h"
#include <QWidget>
#include  <vector>
#include<QMediaPlayer>
namespace Ui {
class gacha_5_times;
}

class gacha_5_times : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_5_times(Gamer* players,QMediaPlayer*p,QWidget *parent = nullptr);
    ~gacha_5_times();
    void paintEvent(QPaintEvent *);

    inline void reshow(){this->show();}
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_goto_widget_clicked();
signals:
    void sendsignal();

private:
    Ui::gacha_5_times *ui;
    Gamer*my_player;
    std::vector<int>*cardnum;
    bool ispushed[5]={0};
    QMediaPlayer*play;
};

#endif // GACHA_5_TIMES_H
