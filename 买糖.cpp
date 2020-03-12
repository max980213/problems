//题目描述：需要买m块糖，超市里的糖按包卖，n种类型，每种类型购买不限次数，第i种有num[i]块糖
//要求正好m块，最少买几包糖

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int num[n];
    int dis[m];
    memset(dis,0,sizeof(dis));
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    queue <int> q;
    q.push(0); //初始状态
    while(!.empty())
    {
        int t=q.front();
        if(t==m)
            break;
        q.pop();
        for(int i=0;i<n;i++) //也许应现对num数组降序排序，等和zyh讨论一下
        {
            int w=num[i]+t;
            if(w<=m&&!dis[w])  //未超过且可访问
            {
                dis[w]=dis[t]+1;
                q.push(w);
            }
        }
    }
}
