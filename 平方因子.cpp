/*
题目描述
给定一个数n，判定它是否有一个不为1的完全平方数因子。也就是说，是否存在某个k，k>1，使得k*k能够整除n。
输入描述:
每行一个整数n，1<n<10000
输出描述:
对于每一个输入的整数，在单独的一行输出结果，如果有不为1的完全平方数因子，则输出Yes，否则输出No。请注意大小写。
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i=2;
    while(i*i<=n)
    {
        if(n%(i*i)==0)
        {
            printf("Yes");
            return 0;
        }
        i++;
    }
    printf("No");
    return 0;
}
