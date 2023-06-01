#ifndef CUTSCENE_H
#define CUTSCENE_H

#include <QWidget>

namespace Ui {
class cutscene;
}

class cutscene : public QWidget
{
    Q_OBJECT

public:
    explicit cutscene(QWidget *parent = nullptr);
    ~cutscene();

private:
    Ui::cutscene *ui;
};

#endif // CUTSCENE_H
