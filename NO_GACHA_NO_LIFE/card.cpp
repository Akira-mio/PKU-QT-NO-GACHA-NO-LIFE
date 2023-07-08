
#include "card.h"

card::card():	weight(-100)
{

}
card::card(int nu,QString na,QString des,int we,int dint,int dst,int dinc,int dmon,int dmov):
    number(nu),name(na),description(des),weight(we),dintellegence(dint),dstrength(dst),dincome(dinc),dmoney(dmon),dmove(dmov)
{

};

