/*
题目描述
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二
 
 十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入描述:
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]]区间内的整数，Sickle是[0, 
17)区间内的整数，Knut是[0, 29)区间内的整数。


输出描述:
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入例子:
10.16.27 14.1.28

输出例子:
3.2.1
*/


#include <stdio.h>

bool cmp(int p[],int a[])
{
    for(int i=0;i<3;i++)
    {
        if(p[i]==a[i])
            continue;
        else if(p[i]>a[i])
            return 1;
        else
            return 0;
    }
    return 0;
}

int main()
{
    int p[3],a[3],carry[3]={0,17,29};
    for(int i=0;i<3;i++)
    {
        scanf("%d",&p[i]);
        getchar();
    }
    //getchar();
    for(int i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
        getchar();
    }
    int ans[3];
    if(cmp(p,a))  //p>a
    {
        putchar('-');
        for(int i=2;i>-1;i--)
        {
            ans[i]=p[i]-a[i];
        }
    }
    else
    {
        for(int i=2;i>-1;i--)
        {
            ans[i]=a[i]-p[i];
        }
    }
    for(int i=2;i>0;i--)
    {
        while(ans[i]<0)
        {
            ans[i]+=carry[i];
            ans[i-1]--;
        }
    }
    printf("%d.%d.%d",ans[0],ans[1],ans[2]);
    return 0;
}
