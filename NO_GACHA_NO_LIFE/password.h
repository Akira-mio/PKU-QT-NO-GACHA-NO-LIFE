#ifndef PASSWORD_H
#define PASSWORD_H
#include <QWidget>
#include<QPushButton>
#include<QMediaPlayer>
namespace Ui {
class password;
}

class password : public QWidget
{
    Q_OBJECT

public:
    explicit password(QString trueending,QMediaPlayer*p,QWidget *parent = nullptr);
    ~password();

private slots:
    void on_lineEdit_returnPressed();

    void goto_trueend();

    void sleep(int time);
private:
    Ui::password *ui;
    QString trueend;
    QPushButton* sendButton;

    QMediaPlayer*p;
};

#endif // PASSWORD_H
