#ifndef SHOPPUSHBUTTON_H
#define SHOPPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>

class shoppushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit shoppushbutton(QWidget *parent = nullptr);
protected:
    void enterEvent(QEnterEvent * event) ;

    void leaveEvent(QEvent * event) ;
    void mouseReleaseEvent(QMouseEvent * event);

signals:

};

#endif // SHOPPUSHBUTTON_H
