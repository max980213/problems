
//约瑟夫环，循环队列
//用链表很合适

#include <stdio.h>
/*  超时了
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int a[n];
        for(int i=0;i<n;i++)
            a[i]=i;
        int j=0;
        int step=0;
        for(int i=0;i<n;i++)  //淘汰n-1次
        {
            while(step<m)
            {
                if(j>=n)
                    j%=n;
                if(a[j++]==-1)
                    continue;
                else
                    step++;
            }
            a[j-1]=-1;
            step=0;
        }
        printf("%d\n",j);
    }
    return 0;
}
*/

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int  r=0 , i ;
        for(i = 2; i <= n; i++)   //第一次只有0
            r = (r + m) % i;  //能用数学解决的就不要用算法
        printf("%d\n", r + 1);
    }
    return 0;
}
