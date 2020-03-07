/*
题目描述
对于给定的正整数 n，计算其十进制形式下所有位置数字之和，并计算其平方的各位数字之和。
输入描述:
每行输入数据包括一个正整数n(0<n<40000)
输出描述:
对于每个输入数据，计算其各位数字之和，以及其平方值的数字之和，输出在一行中，之间用一个空格分隔，但行末不要有空格。
*/

#include <stdio.h>

int geweihe(int n)
{
    int num=0;
    while(n!=0)
    {
        num+=(n%10);
        n/=10;
    }
    return num;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d",geweihe(n),geweihe(n*n));
    return 0;
}
