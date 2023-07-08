#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
protected:
    void enterEvent(QEnterEvent * event) ;

    void leaveEvent(QEvent * event) ;
    void mouseReleaseEvent(QMouseEvent *event);

;

signals:

};

#endif // MYPUSHBUTTON_H
