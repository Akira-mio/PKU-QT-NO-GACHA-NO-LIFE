#ifndef YOURRESTART_H
#define YOURRESTART_H

#include <QDialog>
#include "core_algorithm.h"
namespace Ui {
class yourrestart;
}

class yourrestart : public QDialog
{
    Q_OBJECT

public:
    explicit yourrestart(Gamer* g,QWidget *parent = nullptr);
    int totalnum;
    Gamer* ply;
    ~yourrestart();
signals:
    void sendupdateUI(Gamer*p);
private slots:
    //void on_buttonBox_accepted();

    //void on_buttonBox_rejected();

    void on_sure_clicked();

    void updateUI();
private:
    Ui::yourrestart *ui;
};

#endif // YOURRESTART_H
