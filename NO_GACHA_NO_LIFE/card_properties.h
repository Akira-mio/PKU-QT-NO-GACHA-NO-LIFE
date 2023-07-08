#ifndef CARD_PROPERTIES_H
#define CARD_PROPERTIES_H

#include "core_algorithm.h"
#include <QDialog>
#include<vector>
namespace Ui {
class card_properties;
}

class card_properties : public QDialog
{
    Q_OBJECT

public:
    explicit card_properties(Gamer* players=nullptr,int* cardnum = nullptr,QWidget *parent = nullptr);
    explicit card_properties(Gamer* players=nullptr,std::vector<int>* cardnum = nullptr,QWidget *parent = nullptr);
    ~card_properties();
    int* cardnum;
private slots:
    void on_pushbutton_clicked();

private:
    Ui::card_properties *ui;

};

#endif // CARD_PROPERTIES_H
