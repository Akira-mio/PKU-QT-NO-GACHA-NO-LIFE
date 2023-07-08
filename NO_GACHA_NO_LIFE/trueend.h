#ifndef TRUEEND_H
#define TRUEEND_H

#include <QWidget>
#include<QMediaPlayer>
namespace Ui {
class TrueEnd;
}

class TrueEnd : public QWidget
{
    Q_OBJECT

public:
    explicit TrueEnd(QMediaPlayer*p,QWidget *parent = nullptr);
    ~TrueEnd();

    void paintEvent(QPaintEvent *);


private slots:
    void on_goto_end_clicked();

private:
    Ui::TrueEnd *ui;
    bool flag=0;
    QMediaPlayer*p;
};

#endif // TRUEEND_H
