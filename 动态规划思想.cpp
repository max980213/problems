#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>  //memset

using namespace std;

const int maxn=1010;


//动态规划思想：用于解决最优解的问题，将一个复杂的问题分解为若干子问题
//综合子问题的最优解得到全局的最优解


//1.动态规划的递归写法：斐波那契数列
//对于原来的写法，会涉及很多重复的计算。故可以设置数组dp[]，把已经求得直接存起来

int dp[maxn];  //初始化为-1，表示没计算过
//memset()  外面只能定义，main函数才是程序的开始

int fib(int n)
{
    if(n==0||n==1)
        return 1; //递归边界
    if(dp[n]!=-1)
        return dp[n]; //之前算过了
    else
    {
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
}




//动态规划的递推写法
//1.数塔问题：第i层有i个数，从第一层到最后一层的最大数和？每次只能走左边或右边
//暴力法会超时，复杂度2^n
//从最底层开始，逐一统计该点到最底层的最短，显然最底层就是它自身
//然后依次上层，与下层决策进行比较，逐一选择最优方案


void tower()
{
    int tower[maxn][maxn];
    int dp[maxn][maxn];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&tower[i][j]);  //建立塔
        }
    }
    for(int j=1;j<=n;j++)
    {
        dp[n][j]=tower[n][j];
    }

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+tower[i][j];   //根据下一层更新自己
        }
    }

    printf("%d",dp[1][1]);  //得到了最优解
}



//2.最大连续子序列和
//暴力法复杂度为N^3
//稍微思考以下，用动态规划思想，只看右边的端点，统计以该店为终点的最大子序列
//从最小的端点开始，该值即为它本身
//逐个右移计算

void seq()
{
    int A[maxn];
    int dp[maxn];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    //边界
    dp[0]=A[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+A[i],A[i]);
    }
    //此时dp存放了以i为A[i]为结尾的最大子序列和，需要遍历一遍找到最大的
    int k=0;
    for(int i=1;i<n;i++)
        if(dp[i]>dp[k])
            k=i;
    printf("%d",dp[k]);
}

int main()
{
    memset(dp,-1,sizeof(dp));
}
