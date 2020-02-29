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

/*
int main()   //这种方法会导致vector太大，导致42以后的无法正常运行
{
    vector<int> age;
    age.push_back(0);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n!=0)
        {
            n--;
            for(vector<int>::iterator it=age.begin();it!=age.end();it++)
            {
                (*it)++;    //不打括号会死循环，优先级导致运算符结合顺序不同
            }
            vector<int>::iterator enddd=age.end();
            for(vector<int>::iterator it=age.begin();it!=enddd;it++)
            {
                if((*it)>=5)
                {
                    age.push_back(0);
                }
            }
        }
        cout<<age.size()<<endl;
        age.clear();
        age.push_back(0);
       // cout<<age.size()<<endl;
    }
    //cout<<age.size()<<endl;
    return 0;
}
*/
