#include <stdio.h>
#include <algorithm>

using namespace std;

const int n=101;

int createprime(int a[],int n)
{
    bool num[n];
    fill(num,num+n,1);
    num[0]=num[1]=0;
    num[2]=1;
    for(int i=2;i<n;i++)
    {
        if(num[i]==1)
        {
            for(int j=i+i;j<n;j+=i)
                num[j]=0; //埃氏筛法
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]==1)
        {
           // printf("%d ",i);
            a[cnt++]=i;
        }

    }
    return cnt;
}

int main()
{
    int a[n];
    int cnt=createprime(a,n);
    int m;
    scanf("%d",&m);
    if(m<2)
    {
        printf("0");
        return 0;
    }

    for(int i=0;i<cnt;i++)
    {
        while(m%a[i]==0)
        {
            printf("%d ",a[i]);
            m/=a[i];
            if(m!=1)
                printf("* ");
        }
    }
}
