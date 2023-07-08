#ifndef TO_START_H
#define TO_START_H

#include <QWidget>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
namespace Ui {
class to_start;
}

class to_start : public QWidget
{
    Q_OBJECT

public:
    explicit to_start(QMediaPlayer*p=nullptr,QWidget *parent = nullptr);
    ~to_start();
    inline void reshow(){
        this->show();
    }
private slots:

    void on_loaddata_clicked();

    void on_newgame_clicked();

    void on_diyc_clicked();

private:
    Ui::to_start *ui;
    QMediaPlayer* play;
};

#endif // TO_START_H
