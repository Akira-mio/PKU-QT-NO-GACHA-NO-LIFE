#ifndef RANDOM_H
#define RANDOM_H
#include "core_algorithm.h"
#include "news.h"
#include <QDialog>

namespace Ui {
class random;
}

class random : public QDialog
{
    Q_OBJECT

public:
    explicit random(Gamer*players=nullptr,QWidget *parent = nullptr);
    news* n;
    Gamer* g;
    ~random();
signals:
    void sendupdateUI(Gamer*p);
private slots:
    void on_pushButton_clicked();

    void on_choice1_clicked();

    void on_choice2_clicked();

    void on_choice3_clicked();

    void updateUI();

    void Sleep(int time);

    void setui1();
    void setui2();
    void setui3();

private:
    Ui::random *ui;
    //Gamer*my_player;

};

#endif // RANDOM_H
