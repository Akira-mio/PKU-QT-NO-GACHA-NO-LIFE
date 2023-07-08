#ifndef DIYCARD_H
#define DIYCARD_H

#include <QWidget>
#include<QMediaPlayer>

namespace Ui {
class diycard;
}

class diycard : public QWidget
{
    Q_OBJECT

public:
    explicit diycard(QMediaPlayer*p,QWidget *parent = nullptr);
    ~diycard();
    void delete_space();
    bool check_num();
    void save();
    QString content[21][9];
    int endline=21;
    QMediaPlayer* music;

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::diycard *ui;
};

#endif // DIYCARD_H
