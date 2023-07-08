#ifndef CUTSCENE_H
#define CUTSCENE_H
#include "core_algorithm.h"
#include "theend.h"
#include <QWidget>
#include<QAudioOutput>
#include<QVideoWidget>
#include<QMediaPlayer>
namespace Ui {
class cutscene;
}

class cutscene : public QWidget
{
    Q_OBJECT

public:
    explicit cutscene(Gamer*players,QMediaPlayer*p,QWidget *parent = nullptr);
    ~cutscene();


private:
    Ui::cutscene *ui;
    Gamer*my_player;
    QMediaPlayer*p;
signals:
    void sendsignal();
private slots:
    void on_goto_nextday_clicked();
    void on_save_data_clicked();
    void on_backtomenu_clicked();
};

#endif // CUTSCENE_H
