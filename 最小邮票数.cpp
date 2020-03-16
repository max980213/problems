//只能选一次，考虑DFS
//对于每个数，要么选要么不选
//故复杂度为2^n

#include <iostream>

#define maxn 10000000

using namespace std;

int n,m;
int price[maxn];
int layer=maxn;

void DFS(int index,int step,int sumC,int m)  //正在访问的，当前层数，当前总和，需求总和
{
    if(sumC==m)  //先判断等不等，可能加上最后一个等了
    {
        if(step<layer)
        {
            layer=step;
            return;
        }
    }
    if(index==n||sumC>m)  //访问到最后一个了,index==n是因为第n-1个还得选
        return;
    DFS(index+1,step,sumC,m); //不选第index个
    if(sumC+price[index]<=m)  //如果不超过
        DFS(index+1,step+1,sumC+price[index],m);
}

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
        cin>>price[i];
    DFS(0,0,0,m);
    if(layer!=maxn)
        cout<<layer;
    else
        cout<<0;
    return 0;
}
