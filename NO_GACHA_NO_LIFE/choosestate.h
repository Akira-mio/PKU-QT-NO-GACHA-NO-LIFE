#ifndef CHOOSESTATE_H
#define CHOOSESTATE_H

#include <QWidget>
#include <core_algorithm.h>

namespace Ui {
class choosestate;
}

class choosestate : public QWidget
{
    Q_OBJECT

public:
    int amount;
    Gamer* ply;
    explicit choosestate(int num,Gamer* g,QWidget *parent = nullptr);
    ~choosestate();
signals:
    void sendupdateUI(Gamer*p);
private slots:

    void on_intelligence_clicked();


    void on_strength_clicked();

    void on_income_clicked();

    void updateUI();
private:
    Ui::choosestate *ui;
};

#endif // CHOOSESTATE_H
