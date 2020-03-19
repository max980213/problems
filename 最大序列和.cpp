/*

给出一个整数序列S，其中有N个数，定义其中一个非空连续子序列T中所有数的和为T的“序列和”。 
对于S的所有非空连续子序列T，求最大的序列和。 变量条件：N为正整数，N≤1000000，结果序列和在范围（-2^63,2^63-1）以内。
*/

//令dp[i]表示以a[i]为结尾的最大序列和
 
#include <stdio.h>
 
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],dp[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=a[i]; //顺便初始化dp
    }
    for(int i=1;i<n;i++) //大就更新
    {
        if(dp[i-1]+a[i]>dp[i])
        {
            dp[i]=dp[i-1]+a[i];
        }
    }
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>temp)
            temp=dp[i];   //此时dp中最大的就是答案
    }
    printf("%d",temp);
}
