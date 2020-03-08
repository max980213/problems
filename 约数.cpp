//输入n个整数,依次输出每个数的约数的个数

#include <stdio.h>
 
int main()
{
    int n,temp;
    scanf("%d",&n);
    int k,num=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        for(k=1;k*k<=temp;k++)
        {
            if(temp%k==0)
            {
                if(k*k!=temp)
                    num+=2;
                else
                    num++;
            }
        }
        printf("%d\n",num);
        num=0;
    }
    return 0;
}
