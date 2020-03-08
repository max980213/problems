/*
题目描述
求正整数N(N>1)的质因数的个数。 相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。
输入描述:
可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)。
输出描述:
对于每组数据，输出N的质因数的个数。
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
const int maxn=1100000;

int prime[maxn],pNum=0; //埃氏筛法获取素数表prime
bool p[maxn]={0};  //如果i是素数，p[i]是0

void find_prime()
{
    for(int i=2;i<maxn;i++)
    {
        if(p[i]==0)  //2是素数已知
        {
            prime[pNum++]=i;
            for(int j=i+i;j<maxn;j+=i)
            {
                p[j]=1;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int mid=(int)sqrt(n);
    find_prime();
    int num=0;
        for(int i=0;i<pNum;i++)
        {
            while(n%prime[i]==0)
            {
                num++;
                n/=prime[i];
            }   
        }
            if(n>mid)
            {
                num++;
                //break;
            }
    printf("%d",num);
    return 0;
}
*/


//以上是埃氏筛法建立素数表
//以下是在埃氏筛法的基础上
//埃氏筛法思想：素数的倍数一定不是素数
//所以，如这个数n可以被2整数，那么直到整除到无法被2整除时，
//它也不能被2的倍数整除了，因此不会进入循环

/*大佬的话

因为任何一个合数都能被一个比它小的质数整除。所以当我们用小质数去分解这个给定的数时，我们已经把他的合数因子分解了。
或者从反面去说，如果出现了一个合数a能整除这个数M，那显然在j =a之前应该有一个质数p < a 能把a整除，而之前反复地用M去除以p直到p不能再整除M 程序才往下执行，那怎么会后来又出现了M中一个合数因子a能被p整除呢？这显然矛盾了。
从而可以推出，程序中能整除M的数都是质数
*/



int main()
{
    int n;
    scanf("%d",&n);
    int mid=(int)sqrt(n);  //可以用二分法
    int num=0;
    for(int i=2;i<=mid;i++)
    {
        while(n%i==0)
        {
            n/=i;
            num++;
        }
        if(n<=1)
            break;
    }
    if(n>=mid)
        num++;
    printf("%d",num);
}
