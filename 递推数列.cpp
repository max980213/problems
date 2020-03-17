//如果a=b+c,则a%n=b%n+c%n
//结合律：a*b%n=( ( a%n )*( b%n ) )%n

//非递归递推
//递归如果不用动态规划，会超时

#include <stdio.h>

int main()
{
    int a0,a1,p,q,k;
    scanf("%d %d %d %d %d",&a0,&a1,&p,&q,&k);
    int ans[k+1];
    ans[0]=a0;
    ans[1]=a1;
    for(int i=2;i<=k;i++)
    {
        ans[i]=(p*ans[i-1]%10000+q*ans[i-2]%10000)%10000;
    }
    printf("%d",ans[k]);
    return 0;
}
