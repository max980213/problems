#include <stdio.h>
 
int main()
{
    int a[56],b[56],ans[56];  //a表示新生的，b表示能生的
    a[1]=0;b[1]=1;ans[1]=1;
    for(int i=2;i<56;i++)
    {
        b[i]=b[i-1];
        if(i>3)
            b[i]+=a[i-3];
        a[i]=b[i];
        ans[i]=ans[i-1]+a[i];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
