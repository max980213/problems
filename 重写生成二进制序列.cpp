#include <stdio.h>
#include <string.h>

bool isequal(int a[],int i,int j,int n)  //用来判断两个n位二进制数是否相等，逐位比较
{
    for(int step=0;step<n;step++)
    {
        if(a[i+step]!=a[j+step])
            return 0; //不等
    }
    return 1;
}

int exchange(int a[],int i,int n)  //回溯，返回回溯到的那个二进制数的起始位下标，每次修改第i个数的最后一位
{
    while(a[i+n-1]==1)  //因为最开始是初始化位0，故如果该位是1说明已经修改过，则需要再往回找
    {
        a[i+n-1]=0;
        i--;
    }
    a[i+n-1]=1;
    return i;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    m=1<<n;  //移位会更快
    int a[m+n];  //多n位则不需考虑循环队列，最后一个二进制数的后几位需要从开头开始
                //循环重合的那几位不会被修改，因为二进制数位是n，第1个数是已经被确认的十进制0，回溯的话是从第二个数的最后一位开始的
    memset(a,0,sizeof(a));  //初始化0，初始化1也可，也可从键盘接收初始化值
    for(int k=1;k<m;k++)
    {
        for(int i=0;i<k;i++)  //自己不需要与自己比较
        {
            if(isequal(a,i,k,n))  //存在相等，需要回溯
            {
                k=exchange(a,k,n); //回到新的回溯的位置
                i=0; //需要重新比较
            }
        }
    }
    for(int i=0;i<m;i++)
        printf("%d",a[i]);
    return 0;
}
