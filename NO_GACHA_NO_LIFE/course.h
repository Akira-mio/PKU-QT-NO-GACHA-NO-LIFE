#ifndef COURSE_H
#define COURSE_H
#include <QWidget>
#include <QDialog>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
namespace Ui {
class course;
}

class course : public QDialog
{
    Q_OBJECT

public:
    explicit course(QMediaPlayer*p=nullptr,QWidget *parent = nullptr);
    ~course();

private slots:
    void on_pushButton_clicked();

private:
    Ui::course *ui;
    QMediaPlayer* play;
};

#endif // COURSE_H
