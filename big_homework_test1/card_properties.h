#ifndef CARD_PROPERTIES_H
#define CARD_PROPERTIES_H

#include <QDialog>

namespace Ui {
class card_properties;
}

class card_properties : public QDialog
{
    Q_OBJECT

public:
    explicit card_properties(QWidget *parent = nullptr);
    ~card_properties();

private slots:
    void on_pushButton_clicked();

private:
    Ui::card_properties *ui;
};

#endif // CARD_PROPERTIES_H
