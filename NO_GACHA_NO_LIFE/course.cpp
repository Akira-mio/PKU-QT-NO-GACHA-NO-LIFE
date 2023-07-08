#include "course.h"
#include "ui_course.h"
#include "core_algorithm.h"
#include "widget.h"
#include "news.h"
#include"random.h"
#include<QStringAlgorithms>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>
#include<QVideoWidget>
course::course(QMediaPlayer*p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course)
{
    ui->setupUi(this);
    play=p;
    this->setStyleSheet("color:rgb(255,255,255)");
    this->setFixedSize(this->size());
    QPalette pa(this->palette());
    QImage img = QImage(":/pictures/to_start_background.jpg");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    //this->setAutoFillBackground(true);
    this->setPalette(pa);
    ui->Course->setText(QString("<html><body>"
                            "<p>你睁开眼睛，这个世界好像跟原本的世界没有什么本质不同。</p>"
                            "<p>除了，你在这个世界一切的行动似乎全都由抽卡决定！</p>"
                            "<p>银铃般的声音再次响起。</p>"
                            "<p>“欢迎来到我的抽卡世界。或许你会觉得十分熟悉，但这个世界和你原本的世界没有什么必然联系呦，请不要瞎想~”</p>"
                            "<p>“你拥有三种基本属性，智力，体力和收入。智力越高，运气会越好；体力越高，行动力会越多；收入越高，每天获得的金币数会越多。”</p>"
                            "<p>“行动力是你一天最大能获取的卡牌次数，用不用完是你的权利，但是用不完的也不会保留到下一天哟，这么有趣的生活，就这么睡过去岂不是太可惜了~”</p>"
                            "<p>“1000金币可以用来五连抽，你可以选择至多行动力张数的卡牌收入囊中。金币也可以用来购买丰富多彩的道具~”</p>"
                            "<p>“这个世界福利很好！单抽是免费的呦，不过免费的东西，总归有点代价呢，抽出来就不能反悔了呢~”</p>"
                            "<p>“注意哟，你在选择这张卡牌之前是看不到具体属性的哟。你问我是故意的还是不小心的？是故意的哟，只有保留一点刺激感，才知道你玩的是抽卡游戏~”</p>"
                            "<p>“某一项基本属性高于100或低于0，你在这个世界的旅程就会结束呦。祝你玩的开心~”</p>"
                            "</body></html>"  ) );
    ui->Course->setWordWrap(1);
}

course::~course()
{
    delete ui;
}

void course::on_pushButton_clicked()
{
    Gamer* players= new Gamer;
    players->gameStart();
    players->dayStart();
    players->setLuck();
    players->putCard();
    this->close();
    players->randomEvent();
    Widget *w=new Widget(players,play);
    if(1){

      random*ran = new random(players);

      ran->setParent(w);
      ran->setModal(1);
      ran->setWindowFlags(Qt::Dialog);
      connect(ran,SIGNAL(sendupdateUI(Gamer*)),w,SLOT(updateUI(Gamer*)));
      ran->show();
    }
        w->show();

}

