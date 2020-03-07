/*
题目描述
在组合数学中，我们学过排列数。从n个不同元素中取出m（m<=n）个元素的所有排列的个数，叫做从n中取m的排列数，记为p(n, m)。
具体计算方法为p(n, m)=n(n-1)(n-2)……(n-m+1)= n!/(n-m)! (规定0!=1).
当n和m不是很小时，这个排列数是比较大的数值，比如  p(10,5)=30240。
如果用二进制表示为p(10,5)=30240=( 111011000100000)b，也就是说，最后面有5个零。
我们的问题就是，给定一个排列数，算出其二进制表示的后面有多少个连续的零。
输入描述:
输入包含多组测试数据，每组测试数据一行。
每行两个整数，n和m，0<m<=n<=10000，n=0标志输入结束，该组数据不用处理。
输出描述:
对于每个输入，输出排列数p(n, m)的二进制表示后面有多少个连续的零。每个输出放在一行。
*/

#include <stdio.h>
/*
long long pailie(int n,int m)
{
    long long q=1;;
    for(int i=n;i>n-m;i--)
    {
        q=q*n;
    }
    return q;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long ans=pailie(n,m);
    int num=0;
    while(ans%2==0&&ans!=0)
    {
        num++;
        ans/=2;
    }
    printf("%d",num);
    return 0;
}
*/     //暴力法会导致越界

//更好的思路是，对于n(n-1)......(n-m+1);
//把它当成一个数来看，这个式子就是它的分解
//那么把分解后的数逐个进行模2运算，与算出来后再模2是一样的
//分开统计，num累加，不会越界


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //
    int num=0;
    int temp;
    for(int i=n;i>n-m;i--)
    {
        temp=i;
        while(temp%2==0&&temp!=0)
        {
            num++;
            temp/=2;
        }
    }
    printf("%d",num);
    return 0;
}
