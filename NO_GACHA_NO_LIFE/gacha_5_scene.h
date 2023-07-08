#ifndef GACHA_5_SCENE_H
#define GACHA_5_SCENE_H

#include <QWidget>
#include<core_algorithm.h>
#include<QMediaPlayer>
namespace Ui {
class gacha_5_scene;
}

class gacha_5_scene : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_5_scene(Gamer*,QMediaPlayer*,QWidget *parent = nullptr);
    ~gacha_5_scene();
    Gamer * g5player;

    void paintEvent(QPaintEvent *);



private slots:
    void on_pushButton_clicked();

private:
    Ui::gacha_5_scene *ui;
    QMediaPlayer*play;
};

#endif // GACHA_5_SCENE_H
