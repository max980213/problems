/*
题目描述
在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下: 
距离s           票价 0<S<=L1         C1 L1<S<=L2        C2 L2<S<=L3        C3 
输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9。 每两个站之间的距离不超过L3。 
当乘客要移动的两个站的距离大于L3的时候，可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。 
现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。
然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。
根据输入，输出乘客从A到B站的最小花费。
输入描述:
以如下格式输入数据：
L1  L2  L3  C1  C2  C3
A  B
N
a[2]
a[3]
……
a[N]

*/


//设置dp数组，记录从起点到每一站的最小花费
//dp[end]即到终点的最小花费
//a[i]表示到第0站的距离

//我的错误在，dp[i]不止与dp[i-1]有关
//存在多种可能，如在中间任何一处换乘，是策略最优

#include <stdio.h>
#include <algorithm>

using namespace std;
int L1,L2,L3,C1,C2,C3,A,B,N;

int calcharge(int dis)  //计算花多少钱
{
    int charge;
    if(0<dis&&dis<=L1)
        charge=C1;
    else if(L1<dis&&dis<=L2)
        charge=C2;
    else
        charge=C3;     //存下来这两站画多少钱
    return charge;
}

int main()
{

    scanf("%d %d %d %d %d %d %d %d %d",&L1,&L2,&L3,&C1,&C2,&C3,&A,&B,&N);   //A、B那就应该是起点的下标
    int a[N+1],dp[N+1];  //直接令下标从1开始
    fill(dp,dp+N+1,9999999999999); //初始化为一个大数
    dp[A]=0;
    a[1]=0;
   // int dis=0;  //记录当前连续行驶的路程，超过L3必须换乘
    for(int i=2;i<N+1;i++)
    {
        scanf("%d",&a[i]);
     //   a[i]=a[i]-a[i-1];       //直接记录相邻两站的距离
    }

    for(int i=A+1;i<=B;i++)  
    {
         for(int j=A;j<i;j++) //枚举中间换乘点（dp存储的是起点到i点最小花费）
         {
             int dis=a[i]-a[j]; //计算该两点的距离   
             int temp=calcharge(dis);
             if(dis<=L3&&dp[j]+temp<dp[i])  //如果从j站买票能更省钱
             {
                 dp[i]=dp[j]+temp;
             }
         }//如果是跳跃式前进花费最小，则j遍历到跳跃路过的点时，那一点的dp值也一定是之前跳跃来的
    }

    //此时dp[B]即为结果

    printf("%d",dp[B]);
    return 0;

}
