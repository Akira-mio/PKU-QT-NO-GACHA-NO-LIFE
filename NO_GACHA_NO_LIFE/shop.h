#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include "core_algorithm.h"

namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    Gamer* gamer;
    explicit shop(Gamer* g, QWidget *parent = nullptr);
    void coffee(Gamer* g);
    void seniors_note(Gamer* g);
    void treehole_note(Gamer* g);
    void random_restart(Gamer* g);
    void your_restart(Gamer* g);
    void secret_password(Gamer* g);
    void stop_bad(Gamer* g);
    void stop_good(Gamer* g);
    void fourleaf(Gamer* g);
    void makesame(Gamer* g);
    void lottery(Gamer* g);
    ~shop();
signals:
    void sendupdateUI(Gamer*p);
private slots:
    void on_coffee_clicked();

    void on_goodnote_clicked();

    void on_badnote_clicked();

    void on_random_clicked();

    void on_your_clicked();

    void on_password_clicked();

    void on_fourleaves_clicked();

    void on_stopgood_clicked();

    void on_stopbad_clicked();

    void on_same_clicked();

    void updateUI();
    void on_lottery_clicked();

private:
    Ui::shop *ui;
};

#endif // SHOP_H
