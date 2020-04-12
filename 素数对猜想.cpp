/*
题目描述
让我们定义 dn 为：dn = pn+1 - pn ，其中 pi 是第i个素数。显然有 d1 =1 且对于n&gt1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
 
 现给定任意正整数N (< 105 )，请计算不超过N的满足猜想的素数对的个数。

输入描述:
每个测试输入包含1个测试用例，给出正整数N。


输出描述:
每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入例子:
20

输出例子:
4
*/




//不如省掉花里胡哨

#include <stdio.h>

bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int lastprime=2,num=0;
    for(int i=3;i<=n;i++)
    {
        if(isprime(i))
        {
            if(i-lastprime==2)
            {
                num++;
            }
            lastprime=i;
        }
    }
    printf("%d",num);
    return 0;
}
