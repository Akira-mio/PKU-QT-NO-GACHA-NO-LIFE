#ifndef GACHA_1_TIME_H
#define GACHA_1_TIME_H

#include <QWidget>

namespace Ui {
class gacha_1_time;
}

class gacha_1_time : public QWidget
{
    Q_OBJECT

public:
    explicit gacha_1_time(QWidget *parent = nullptr);
    ~gacha_1_time();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gacha_1_time *ui;
};

#endif // GACHA_1_TIME_H
