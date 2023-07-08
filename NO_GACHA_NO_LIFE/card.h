
#ifndef CARD_H
#define CARD_H


#include <QObject>


class card:public QObject
{
    Q_OBJECT
public:
    int number;
    QString name;
    QString description;
    int weight;

    //属性增减
    int dintellegence;
    int dstrength;
    int dincome;
    int dmoney;
    int dmove;
    card();
    card(int nu,QString na,QString des,int we,int dint,int dst,int dinc,int dmon,int dmov);
};

#endif // CARD_H
