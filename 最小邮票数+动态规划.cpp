#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int w[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int dp[m+1];
    fill(dp+1,dp+1+m,1000000000);
    dp[0]=0;
    
    //现尝试用动态规划解决
//因为使增序输入，正好不需要排序
//设置dp数组，令dp[w]表示最大价值为刚好装入最少可放多少个票
    
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=0;j--)
        {  //逆序枚举
            if(j>=w[i])
            {
                dp[j]=min(dp[j],dp[j-w[i]]+1);
            }
        }
    }
    if(dp[m]==1000000000)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<dp[m]<<endl;
    } 
    return 0;
}
