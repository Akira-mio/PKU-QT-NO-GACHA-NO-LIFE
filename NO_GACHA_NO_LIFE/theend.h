#ifndef THEEND_H
#define THEEND_H
#include "core_algorithm.h"
#include <QDialog>
#include<QMediaPlayer>
namespace Ui {
class TheEnd;
}

class TheEnd : public QDialog
{
    Q_OBJECT

public:
    explicit TheEnd(Gamer*players,QMediaPlayer*p,QWidget *parent = nullptr);
    ~TheEnd();

    void paintEvent(QPaintEvent *);

    Gamer* endplayer;
    QMediaPlayer*p;

private slots:
    void on_new_game_clicked();

    void on_gameover_clicked();

    void goto_password();
private:
    Ui::TheEnd *ui;
    QPushButton* sendButton;
    int trueend;
};

#endif // THEEND_H
