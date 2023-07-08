
#ifndef CHARACTER_H
#define CHARACTER_H


#include <QObject>


class character:public QObject
{
    Q_OBJECT
public:
    int intellegence;//智力
    int strength;//体力
    int income;//收入
    int money;//金钱
    int move;//行动力
    int luck;//幸运值
    character();
};

#endif // CHARACTER_H
