#ifndef TO_START_H
#define TO_START_H

#include <QWidget>

namespace Ui {
class to_start;
}

class to_start : public QWidget
{
    Q_OBJECT

public:
    explicit to_start(QWidget *parent = nullptr);
    ~to_start();

private slots:
    void on_pushButton_clicked();

private:
    Ui::to_start *ui;
};

#endif // TO_START_H
