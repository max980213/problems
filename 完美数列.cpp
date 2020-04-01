/*
给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
*/



//稍微用一下动态规划？
//我又理解错了，原来可以不连续，随便挑

/*

#include <stdio.h>

int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    int a[n],dp[n];  //dp[i]表示以第i位为结尾之前的最大完美子序列
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    dp[0]=1;  //自己只能自成序列
    int m=a[0],M=a[0]; 
    for(int i=1;i<n;i++)
    {
        if(a[i]>M)
        {
            if(m*p>=a[i])
            {
                dp[i]=dp[i-1]+1;
                M=a[i];   //符合要求，并入序列
            }
            else  //不符，重新开始，这是在该数大于之前的最大的情况下
            {     //理解错误，直接继承即可
                dp[i]=dp[i-1];
               // m=M=a[i]; //重新开始  //不需要了
            }
                
        }
        else if(a[i]<m)
        {
            if(a[i]*p>=M)
            {
                dp[i]=dp[i-1]+1;
                m=a[i];
            }
            else
            {
                dp[i]=dp[i-1];
               // m=M=a[i];
            }  
        }
        else  //如果夹在最大最小之间，必然符合
        {
            dp1[i]=dp[i-1]+1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>ans)
            ans=dp[i];
    }
    printf("%d",ans);
    return 0;
}

*/

//这种方法不行，忽略了一种情况
//假设序列为3，6，2，8，7，7，7，7，7，7，7.....
//2并入后，8和7均不会并入
//若不并入2，很多7是构成完美数列的，但上面的算法设置是一定会并入2
//即使排过序，也会并入2

#include <stdio.h>
#include <algorithm>  //先排个序，利用两指针的方法比较，也许注定要两层循环吧

using namespace std;

int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);  //默认增序
    int max=0;   //好像甚至不需要dp数组
    int start=0; //先记录以下最大序列开始的位置，因为并入更大的数的时候已经不需要从头开始了
    for(int i=1;i<n;i++)//依次比较数组a[i]
    {
        for(int j=start;j<i;j++)
        {
            if(i-j+1<=max)
                break;  //没那么多了，不需再比较
            if(a[j]*p>=a[i]&&i-j+1>max)
            {
                max=i-j+1;
                start=j;
                break;
            }
        }
    }
    printf("%d",max);
    return 0;
}
