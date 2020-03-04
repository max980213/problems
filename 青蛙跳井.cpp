//问题描述：一口高h的井，白天跳m，晚上休息落n，问多少天跳出去

#include <stdio.h>
const int maxn=1010;
int main()
{
    int ans[1010];
    int i=0;

    int h,m,n;
    while(1)
    {
    scanf("%d",&h);
    if(h==0)
        break;
    scanf("%d %d",&m,&n);
    getchar();
    int climb=0;
    int daynum=0;
    int net=m-n;
    while(climb<h)
    {
        daynum++;
        if(climb+m>=h)
            break;
        climb+=net;
        //daynum++;
    }
    ans[i++]=daynum;
  //  return 0;
    }
    for(int j=0;j<i;j++)
        printf("%d\n",ans[j]);
    return 0;
}
