#include <stdio.h>
#include <string.h>

/*
bool isprime(int n)  //暴力法会超时
{
    if(n<=1)
        return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

const int maxn=1000001;

int prime[maxn];
bool is[maxn];

int create()
{
    memset(is,0,sizeof(is));  //memset只能初始化为0或-1
    int num=0;
    for(long long int i=2;i<maxn;i++)
    {
        if(is[i]==0)
        {
            prime[num++]=i;
            for(long long int j=i*i;j<maxn;j+=i)  //直接从i*i开始，因为2*i被2筛走了，i-1)*i被i-1筛走了
                                        //原来是j=i*i后j超过了int的表示范围！！！！！
                is[j]=1;
        }
    }
    return num;
}

int main()
{
    int n;
    int num=create();
    while(scanf("%d",&n)!=EOF)
    {
    printf("%d = ",n);
        /*
    for(int i=2;n!=1;i++)   //暴力法会超时
    {
        if(isprime(i))
        {
            while(n%i==0)
            {
                n/=i;
                if(n!=1)
                {
                    printf("%d * ",i);
                }
                else
                {
                    printf("%d",i);
                    break;
                }
            }
        }
    }
    }
    
    for(int i=0;i<num&&n!=1;i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            if(n!=1)
            {
                printf("%d * ",prime[i]);
            }
            else
            {
                printf("%d\n",prime[i]);
                break;
            }
        }
    }





    }
    return 0;
}
*/    //其实并不需要建立素数表，因为再除的过程中，所有非素数因子都会被素数因子除掉
      //即，假设遍历到4，这个数已经不会被4整除了，反证法，若可整除，那么在i=2的时候应该继续筛



int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d = ",n);
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                n/=i;
                if(n!=1)
                {
                    printf("%d * ",i);
                }
                else
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
        if(n!=1)
            printf("%d\n",n);
    }
    return 0;
}
