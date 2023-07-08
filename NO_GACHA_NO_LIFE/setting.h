#ifndef SETTING_H
#define SETTING_H
#include <QWidget>
#include <QDialog>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QMediaPlayer*p=nullptr,QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_goto_course_clicked();

private:
    Ui::setting *ui;
    QMediaPlayer* play;
};

#endif // SETTING_H
