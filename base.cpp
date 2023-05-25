#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<random>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int date=0;
int gameEnd=0;
class character {
public:
	int intellegence;//智力
	int strength;//体力
	int income;//收入
	int money;//金钱
	int move;//行动力
	int luck;//幸运值
	character() :intellegence(50), income(50), strength(50), money(0), move(0),luck(0) {};
} player;


class card {
public:
	int number;
	string name;
	string description;
	int weight;

	//属性增减
	int dintellegence;
	int dstrength;
	int dincome;
	int dmoney;
	int dmove;
	card():	weight(-100){};
	card(int nu,string na,string des,int we,int dint,int dst,int dinc,int dmon,int dmov):number(nu),name(na),description(des),weight(we),dintellegence(dint),dstrength(dst),dincome(dinc),dmoney(dmon),dmove(dmov){};
};

class news {
public:
	int number;
	string name;
	string description;

	//属性增减
	int dintellegence;
	int dstrength;
	int dincome;
	int dmoney;
	int dmove;
	news(int nu,string na,string des,int dint,int dst,int dinc,int dmon,int dmov):number(nu),name(na),description(des),dintellegence(dint),dstrength(dst),dincome(dinc),dmoney(dmon),dmove(dmov){};
};
void gameStart();
void day();//进行一天的事件
void dayStart();//一天的开始工作
void setLuck();//设定今日幸运值
void putCard();//每一天开始时，将卡放入卡池
void randomEvent();//随机事件
void drawACard();//单抽
void drawTenCard();//十连
void chooseCard(int cardNumber);//玩家选择卡
void dayEnd();//一天的结束工作
bool judgeEnd();//判断游戏结束条件

card cardLibrary[500];
vector<news> newsPool;
vector<int> cardPool;//卡池
void gameStart(){
	//读取卡牌信息
	freopen("card.txt","r",stdin);
	int num;
	while (cin>>num){
		if (num==999) break;
		string name,description;
		int weight,dintellegence,dstrength,dincome,dmoney,dmove;
		cin>>name>>description>>weight>>dintellegence>>dstrength>>dincome>>dmoney>>dmove;
		cardLibrary[num]=card(num,name,description,weight,dintellegence,dstrength,dincome,dmoney,dmove);
	}
	fclose(stdin);
	cin.clear();
	//读取随机事件信息
	freopen("news.txt","r",stdin);
	while (cin>>num){
		if (num==999) break;
		string name,description;
		int dintellegence,dstrength,dincome,dmoney,dmove;
		cin>>name>>description>>dintellegence>>dstrength>>dincome>>dmoney>>dmove;
		newsPool.push_back(news(num,name,description,dintellegence,dstrength,dincome,dmoney,dmove));
	}
	fclose(stdin);
	cin.clear();
	//重定向至键盘输入
	freopen("CON", "r", stdin); 
}
void day() {
	dayStart();
	setLuck();
	putCard();
	randomEvent();
	if (judgeEnd()) return;
	int n;
	while (player.move > 0) {
		cout << "income:" << player.income << endl;
		cout << "intellegence:" << player.intellegence << endl;
		cout << "strength:" << player.strength << endl;
		cout << "money:" << player.money << endl;
		cout << "move:" << player.move << endl;
		if (judgeEnd()) return;
		cout << "1.单抽 10.十连(1000块钱) 0.下一天"<<endl;
		cin >> n;//TODO:改为点击鼠标选择单抽/十连/进入下一天
		if (n == 1) drawACard();
		if (n == 10) {
			if (player.money>=1000) drawTenCard();
			else  cout<<"钱不够!"<<endl;
		}
		if (n == 0) break;
		if (judgeEnd()) return;
	}
}

void dayStart() {
	date++;
	cout<<"DAY"<<date<<":"<<endl;
	player.money += player.income * 10;
	player.move = max(player.strength/15, 1);
	//TODO:转场界面
}
int luckPool[10] = { 0,1,1,2,2,2,2,3,3,4 };
void setLuck() {
	player.luck = luckPool[rand() % 10];
	cout<<"今日运势：";
	switch (player.luck) {
	case 0:cout << "大凶" << endl; break;
	case 1:cout << "凶" << endl; break;
	case 2:cout << "中平" << endl; break;
	case 3:cout << "吉" << endl; break;
	case 4:cout << "大吉" << endl; break;
	}
	player.luck+=player.intellegence/25;
	//TODO:抽签界面
}
void putCard(){
	cardPool.clear();
	for (int i=0;i<500;i++){
		for (int j=0;j<cardLibrary[i].weight+player.luck;j++)
			cardPool.push_back(i);
	}
}


void randomEvent() {
	int pos = rand() % newsPool.size();
	news today_event= newsPool[pos];
	newsPool.erase(newsPool.begin() + pos);//从新闻池中删去事件，保证同一局不再触发
	cout << today_event.name << endl;
	cout << today_event.description << endl;
	player.income += today_event.dincome;
	player.intellegence += today_event.dintellegence;
	player.strength += today_event.dstrength;
	player.money += today_event.dmoney;
	player.move += today_event.dmove;
	if (today_event.dincome != 0) cout << "income+" << today_event.dincome << endl;
	if (today_event.dintellegence != 0) cout << "intellegence+" << today_event.dintellegence << endl;
	if (today_event.dstrength != 0) cout << "strength+" << today_event.dstrength << endl;
	if (today_event.dmoney != 0) cout << "money+" << today_event.dmoney << endl;
	if (today_event.dmove != 0) cout << "move+" << today_event.dmove << endl;
}



void chosenCard(int cardNumber){
	card& chosenCard = cardLibrary[cardNumber];
	cout << chosenCard.name << endl;
	cout << chosenCard.description << endl;
	player.income += chosenCard.dincome;
	player.intellegence += chosenCard.dintellegence;
	player.strength += chosenCard.dstrength;
	player.money += chosenCard.dmoney;
	player.move += chosenCard.dmove;
	if (chosenCard.dincome != 0) cout << "income+" << chosenCard.dincome << endl;
	if (chosenCard.dintellegence != 0) cout << "intellegence+" << chosenCard.dintellegence << endl;
	if (chosenCard.dstrength != 0) cout << "strength+" << chosenCard.dstrength << endl;
	if (chosenCard.dmoney != 0) cout << "money+" << chosenCard.dmoney << endl;
	if (chosenCard.dmove != 0) cout << "move+" << chosenCard.dmove << endl;
	player.move--;
}
void drawACard() {
	int cardNum = cardPool[rand() % cardPool.size()];
	chosenCard(cardNum);
}
void drawTenCard() {
	player.money-=1000;
	vector<int> cardNum;
	for (int i=0;i<10;i++)
		cardNum.push_back(cardPool[rand() % cardPool.size()]);	
	while (player.move > 0) {
		for (int i = 0; i < cardNum.size(); i++)
			cout <<i+1<< cardLibrary[cardNum[i]].name << endl;
		cout<<0<<"都不要了"<<endl;
		int num;
		cin >> num;
		if (num == 0) break;
		chosenCard(cardNum[num-1]);
		cardNum.erase(cardNum.begin()+num-1);
	}
}
bool judgeEnd(){
	gameEnd=1;
	if (player.intellegence>=100){
		cout<<"大聪明"<<endl;
		return true;
	}
	if (player.intellegence<=0){
		cout<<"大笨蛋"<<endl;
		return true;
	}
	if (player.income>=100){
		cout<<"vivo50"<<endl;
		return true;
	}
	if (player.income<=0){
		cout<<"穷的只能吃土"<<endl;
		return true;
	}
	if (player.strength>=100){
		cout<<"叠"<<endl;
		return true;
	}
	if (player.strength<=0){
		cout<<"菜"<<endl;
		return true;
	}
	if (date>20){
		cout<<"太久了"<<endl;
		return true;
	}
	gameEnd=0;
	return false;
}

int main() {
	srand(unsigned(time(0)));
	
	cout << "你好"<<endl;
	gameStart();
	while (!gameEnd){
		day();
	}
	cout<<"game over";
}
