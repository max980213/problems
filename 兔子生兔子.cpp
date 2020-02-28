//题目描述：有一对兔子，从出生后的第5个月每月生一对，小兔子也一样，假设兔子不死，第n个月会有几对兔子



#include <bits/stdc++.h> //包含了常用的头文件

using namespace std;

const int maxn = 105;
int a[maxn];
int b[maxn];
int ans=1;

int main()
{
    b[1]=0; //b[i]表示第i天有多少能生的兔子
    a[1]=1; //a[i]表示第i天有多少新出生的兔子
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        b[i]=b[i-1];
        if(i>=5)
        {
            b[i]+=a[i-4];
        }
        a[i]=b[i];
        ans+=a[i];

    }
    printf("%d\n",ans);
    return 0;
}
