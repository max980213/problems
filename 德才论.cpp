/*
题目描述
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之
小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入描述:
输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格
被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到
但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼
亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。


输出描述:
输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人
总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入例子:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出例子:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

*/


#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct student
{
    int id;
    int mg,tg,sum;
    int rank;
}student;

bool cmp(student a,student b)  //直接利用成绩排序太麻烦了，不如设置一个新变量rank，用来表示是第几类
{
    if(a.rank!=b.rank)
        return a.rank>b.rank;
    else if(a.sum!=b.sum)
        return a.sum>b.sum;
    else if(a.mg!=b.mg)
        return a.mg>b.mg;
    else
        return a.id<b.id;
} //不设置rank的话，每两类之间都需要写if比较

int main()
{
    int n,l,h;
    scanf("%d %d %d",&n,&l,&h);
    student data[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&data[i].id,&data[i].mg,&data[i].tg);
        data[i].sum=data[i].mg+data[i].tg;
        if(data[i].mg>=h&&data[i].tg>=h)
            data[i].rank=5; //最牛逼
        else if(data[i].mg>=h&&data[i].tg<h&&data[i].tg>=l)
            data[i].rank=4; //德胜才
        else if(data[i].mg>=data[i].tg&&data[i].mg<h&&data[i].tg>=l)
            data[i].rank=3;
        else if(data[i].mg>=l&&data[i].tg>=l)
            data[i].rank=2;
        else
            data[i].rank=1;
    }
    sort(data,data+n,cmp);
    int k;
    for(k=n-1;k>-1;k--)
    {
        if(data[k].mg>=l&&data[k].tg>=l)
            break;
    }
    printf("%d\n",k+1);
    for(int i=0;i<=k;i++)
    {
        printf("%d %d %d\n",data[i].id,data[i].mg,data[i].tg);
    }
    return 0;
}
