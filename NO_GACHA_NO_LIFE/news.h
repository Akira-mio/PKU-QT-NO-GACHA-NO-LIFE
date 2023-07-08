
#ifndef NEWS_H
#define NEWS_H


#include <QObject>


class news:public QObject
{
    Q_OBJECT
public:
    int number;
    QString name;

    QString option1;
    int dintellegence1;
    int dstrength1;
    int dincome1;
    int dmoney1;
    int dmove1;

    QString option2;
    int dintellegence2;
    int dstrength2;
    int dincome2;
    int dmoney2;
    int dmove2;

    QString option3;
    int dintellegence3;
    int dstrength3;
    int dincome3;
    int dmoney3;
    int dmove3;
    news(int nu,QString na,QString op1,int dint1,int dst1,int dinc1,int dmon1,int dmo1
         ,QString op2,int dint2,int dst2,int dinc2,int dmon2,int dmo2
         ,QString op3,int dint3,int dst3,int dinc3,int dmon3,int dmo3);
};

#endif // NEWS_H
