#ifndef CORE_ALGORITHM_H
#define CORE_ALGORITHM_H

#endif // CORE_ALGORITHM_H
#include "character.h"
#include "card.h"
#include "news.h"
#pragma once
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QTextStream>
#include <QDir>
#include <iterator>
#define cout qDebug()

class Gamer{
public:
    int luckPool[10] = { 0,1,1,2,2,2,2,3,3,4 };
    character* player=new character;
    int date=0;
    int gameEnd=0;
    int trueending=0;
    int stopbad=0;
    int stopgood=0;
    card* cardLibrary[500];
    std::vector<news*> newsPool;
    std::vector<int> cardPool;//卡池
    std::vector<news*>::iterator today_event;
    void gameStart();
    void day();//进行一天的事件
    void dayStart();//一天的开始工作
    void setLuck();//设定今日幸运值
    void putCard();//每一天开始时，将卡放入卡池
    void randomEvent();//随机事件
    int drawACard();//单抽
    void drawFiveCard();//五连
    void chosenCard(int cardNumber);//玩家选择卡
    void dayEnd();//一天的结束工作
    bool judgeEnd();//判断游戏结束条件
    bool music=1;
};
