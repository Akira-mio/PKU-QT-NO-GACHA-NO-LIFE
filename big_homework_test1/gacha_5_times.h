#ifndef GACHA_5_TIMES_H
#define GACHA_5_TIMES_H

#include <QWidget>

namespace Ui {
class gacha_5_times;
}

class gacha_5_times : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_5_times(QWidget *parent = nullptr);
    ~gacha_5_times();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::gacha_5_times *ui;
};

#endif // GACHA_5_TIMES_H
