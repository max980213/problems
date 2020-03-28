/*
题目描述：读入m，生成一个大小为2^m的环，使环上从任意位置开始的m位二进制数都不相同
如m=3，生成00010111，对应0，1，2，5，3，7，6，4

#include <stdio.h>
#include <string.h>

#define N 1024
#define M 10

int b[N+M-1];

bool equal(int k,int j,int m)  //用来判断两个m位二进制数是否相等，逐位比较
{
    for(int i=0;i<m;i++)
    {
        if(b[k+i]!=b[j+i])
            return 0;
    }
    return 1;
}

int exchange(int k,int m)
{
    while(b[k+m-1]==1)  //因为最开始全初始化为0，所以如果该位为1，说明一定是修改后的，那么再改回0也还是不行，则需要回溯
    {                   //先把已修改为1的恢复为0，再把最近的一个0修改为1，返回该二进制串第一个数位的位置，再进行比较
        b[k+m-1]=0;
        k--;
    }
    b[k+m-1]=1;
    return k;
}

int main()
{
    int m,n,k=0;
    scanf("%d",&m);
    n=0x01<<m; //2^m=n，用移位很方便
    memset(b,0,sizeof(b));   //初始化为0，也可初始化为1，可由键盘接收
    while(++k<n)  //k表示第k个m位数
    {
        for(int i=0;i<k;i++)  //新填入的不需要与自身比较，第一个与最后一个也不需要比较，因为是一个环，数组多开了几位是为了接上环
        {
            if(equal(k,i,m))  //只要存在m位二进制数相等
            {
                k=exchange(k,m);  //k返回了回溯之后的最后一个m位二进制数的起始位置
                i=-1; //因为再需要从i=0开始比较，这次循环结束i会++
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d",b[i]);
    return 0;
}
