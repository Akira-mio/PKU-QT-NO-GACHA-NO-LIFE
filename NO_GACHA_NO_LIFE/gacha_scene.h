#ifndef GACHA_SCENE_H
#define GACHA_SCENE_H

#include <QWidget>
#include<core_algorithm.h>
#include<QMediaPlayer>
namespace Ui {
class gacha_scene;
}

class gacha_scene : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_scene(Gamer* player,QMediaPlayer*p, QWidget *parent = nullptr);
    ~gacha_scene();
    Gamer * gplayer;

    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::gacha_scene *ui;
    QMediaPlayer*play;
};

#endif // GACHA_SCENE_H
