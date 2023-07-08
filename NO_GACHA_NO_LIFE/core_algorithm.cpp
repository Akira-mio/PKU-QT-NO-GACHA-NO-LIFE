#ifndef CORE_ALGORITHM_H
#define CORE_ALGORITHM_H

#endif // CORE_ALGORITHM_H
#include "character.h"
#include "card.h"
#include "news.h"
#include "core_algorithm.h"
#pragma once
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QTextStream>
#include <QDir>

#define cout qDebug()

void Gamer::gameStart(){
    //读取卡牌信息
    for(int i=0;i<500;++i){
        cardLibrary[i]=nullptr;
    }
    cout<<QDir::currentPath();
    QFile file(":/data/card1.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream cin(&file);
    //cout<<file.isOpen();
    //cout<<file.errorString();
    //return;
    if (file.isOpen()){
    //cin.setEncoding (QStringConverter::System);
    int num;
    cin>>num;
    while (num!=999){
        QString name,description;
        int weight,dintellegence,dstrength,dincome,dmoney,dmove;
        //cout<<num;
        cin>>name>>description>>weight>>dintellegence>>dstrength>>dincome>>dmoney>>dmove;
        cardLibrary[num]=new card(num,name,description,weight,dintellegence,dstrength,dincome,dmoney,dmove);
        cin>>num;
    }
    file.close();
    }

    cout<<QDir::currentPath();
    QFile file1(":/data/mycard.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream cin1(&file1);
    //cout<<file.isOpen();
    //cout<<file.errorString();
    //return;
    if (file1.isOpen()){
    //cin.setEncoding (QStringConverter::System);
    int num;
    cin1>>num;
    while (num!=999){
        QString name,description;
        int weight,dintellegence,dstrength,dincome,dmoney,dmove;
        cout<<num;
        cin1>>name>>description>>weight>>dintellegence>>dstrength>>dincome>>dmoney>>dmove;
        cardLibrary[num]=new card(num,name,description,weight,dintellegence,dstrength,dincome,dmoney,dmove);
        cin1>>num;
    }
    file1.close();
    }
    //cout<<1;
    //读取随机事件信息
    QFile file2(":/data/news1.txt");
    file2.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream cin2(&file2);
    int num;
    //cout<<file.isOpen();
    cin2>>num;
    int p;
    while (num!=999){
    QString name,op1,op2,op3,re1,re2,re3;
    //cout<<p++;
    //cout<<num;
        int dintellegence1,dstrength1,dincome1,dmoney1,dmove1,dintellegence2,dstrength2,dincome2,dmoney2,dmove2,dintellegence3,dstrength3,dincome3,dmoney3,dmove3;
        cin2>>name>>op1>>dintellegence1>>dstrength1>>dincome1>>dmoney1>>dmove1;
        cin2>>op2>>dintellegence2>>dstrength2>>dincome2>>dmoney2>>dmove2;
        cin2>>op3>>dintellegence3>>dstrength3>>dincome3>>dmoney3>>dmove3;
        newsPool.push_back(new news(num,name,op1,dintellegence1,dstrength1,dincome1,dmoney1,dmove1,
                                    op2,dintellegence2,dstrength2,dincome2,dmoney2,dmove2,
                                    op3,dintellegence3,dstrength3,dincome3,dmoney3,dmove3));

        //cout<<num<<name<<op1<<dintellegence1<<dstrength1<<dincome1<<dmoney1<<dmove1;
        //cout<<op2<<dintellegence2<<dstrength2<<dincome2<<dmoney2<<dmove2;
        //cout<<op3<<dintellegence3<<dstrength3<<dincome3<<dmoney3<<dmove3;
        cin2>>num;
    }
    file2.close();
    //重定向至键盘输入
    //freopen("CON", "r", stdin);
    cout<<"******";
    //cout<<cardLibrary[200]->number;
    cout<<"******";
}
void Gamer::dayStart() {
    date++;

    cout<<"DAY"<<date<<":";
    player->money += player->income * 10;
    player->move = std::max(player->strength/15, 1);

}

//void Gamer::day() {
//    dayStart();
 //   setLuck();
 //   putCard();
 //   randomEvent();
 //   if (judgeEnd()) return;
 //   int n = 0;
 //   while (player->move > 0) {
  //      cout << "income:" << player->income ;
  //      cout << "intellegence:" << player->intellegence;
  //      cout <<"strength:" << player->strength ;
  //      cout << "money:" << player->money;
  //      cout << "move:" << player->move;
  //      if (judgeEnd()) return;
     //   cout << "1.单抽 10.十连(1000块钱) 0.下一天";
//        //cin >> n;//TODO:改为点击鼠标选择单抽/十连/进入下一天
//        if (n == 1) drawACard();
//        if (n == 10) {
//            if (player->money>=1000) drawFiveCard();
//            else  cout<<"钱不够!";
//        }
//        if (n == 0) break;
//        if (judgeEnd()) return;
 //   }
//}



void Gamer::setLuck() {
    player->luck = luckPool[rand() % 10];
    cout<<"今日运势：";
    switch (player->luck) {
    case 0:cout << "大凶" ; break;
        case 1:cout << "凶" ; break;
        case 2:cout << "中平" ; break;
        case 3:cout << "吉" ; break;
        case 4:cout << "大吉" ; break;
    }
        player->luck+=player->intellegence/25;
    //TODO:抽签界面
}
void Gamer::putCard(){
    //cout<<"*";

    cardPool.clear();
    //cout<<"*8";
    for (int i=1;i<500;i++){
        if(cardLibrary[i]!=nullptr){
            cout<<i;
            for (int j=0;j<cardLibrary[i]->weight+player->luck;j++){
                cardPool.push_back(i);
            }
        }
    }
}


void Gamer::randomEvent() {
    int pos = rand() % newsPool.size();
    //news &today_event = newsPool[pos];
    today_event = newsPool.begin();
    today_event+=pos;
    news* t = *today_event;
    cout << t->name ;
    //cout << t->description ;
    //player->income += t->dincome;
    //player->intellegence += t->dintellegence;
    //->strength += t->dstrength;
    //player->money += t->dmoney;
    //player->move += t->dmove;
    //if (t->dincome != 0) cout << "income+" << t->dincome ;
    //if (t->dintellegence != 0) cout << "intellegence+" << t->dintellegence ;
    //if (t->dstrength != 0) cout << "strength+" << t->dstrength ;
    //if (t->dmoney != 0) cout << "money+" << t->dmoney ;
    //if (t->dmove != 0) cout << "move+" << t->dmove ;
    //newsPool.erase(newsPool.begin() + pos);//从新闻池中删去事件，保证同一局不再触发
}



void Gamer::chosenCard(int cardNumber){
    card& chosenCard = *cardLibrary[cardNumber];
    cout << chosenCard.name ;
    cout << chosenCard.description ;
    player->income += chosenCard.dincome;
    player->intellegence += chosenCard.dintellegence;
    player->strength += chosenCard.dstrength;
    player->money += chosenCard.dmoney;
    player->move += chosenCard.dmove;
    if (chosenCard.dincome != 0) cout << "income+" << chosenCard.dincome ;
    if (chosenCard.dintellegence != 0) cout << "intellegence+" << chosenCard.dintellegence ;
    if (chosenCard.dstrength != 0) cout << "strength+" << chosenCard.dstrength ;
    if (chosenCard.dmoney != 0) cout << "money+" << chosenCard.dmoney ;
    if (chosenCard.dmove != 0) cout << "move+" << chosenCard.dmove ;
    player->move--;
}
int Gamer::drawACard() {
    int cardNum = cardPool[rand() % cardPool.size()];
   return cardNum;
} //chosenCard(cardNum);
void Gamer::drawFiveCard() {
    player->money-=1000;
    std::vector<int> cardNum;
    for (int i=0;i<5;i++)
        cardNum.push_back(cardPool[rand() % cardPool.size()]);
//    while (player->move > 0) {
//        for (int i = 0; i < cardNum.size(); i++)
//            cout <<i+1<< cardLibrary[cardNum[i]]->name;
//        cout<<0<<"都不要了";
//        int num;
//        //cin >> num;//TODO:改为鼠标点击按键选择
//        if (num == 0) break;
//        chosenCard(cardNum[num-1]);
//        cardNum.erase(cardNum.begin()+num-1);
//    }
}
bool Gamer::judgeEnd(){
    gameEnd=1;
    if (player->intellegence>=100){
        cout<<"大聪明";
            return true;
    }
    if (player->intellegence<=0){
        cout<<"大笨蛋";
            return true;
    }
    if (player->income>=100){
        cout<<"vivo50";
        return true;
    }
    if (player->income<=0){
        cout<<"穷的只能吃土";
        return true;
    }
    if (player->strength>=100){
        cout<<"叠";
            return true;
    }
    if (player->strength<=0){
        cout<<"菜";
            return true;
    }
    //if (date>20){
    //    cout<<"太久了";
    //        return true;
    //}
    if (player->income==trueending&&player->intellegence==trueending&&player->strength==trueending&&trueending!=0){
            //真结局
        cout<<"真结局";
       return true;
    }
    gameEnd=0;
    return false;
}
