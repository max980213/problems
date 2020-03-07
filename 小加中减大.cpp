//现有一个更简单的思想：a+b+c-2*max(a,b,c)，太牛逼了，只要三行就搞定，根本不需要排序





#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn=1010;

int mid(int a,int b,int c)
{
    int minn=min(a,min(b,c));
    int maxx=max(a,max(b,c));
    if(minn<a&&a<maxx)
        return a;
    else if(minn<b&&b<maxx)
        return b;
    else
        return c;
}

int main()
{
    int a,b,c;
    int ans[maxn];
    int i=0;
    //while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
       // if(a==0&&b==0&&c==0)
      //      break;
        int minn=min(a,min(b,c));
        int maxx=max(a,max(b,c));
        int midd=mid(a,b,c);
        ans[i++]=minn+midd-maxx;
    }
    for(int j=0;j<i;j++)
        printf("%d\n",ans[j]);
    return 0;
}
