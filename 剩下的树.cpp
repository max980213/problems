/*
题目描述
    有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，
    起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。
    现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
    可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
*/

#include <stdio.h>
#include <string.h>

//巧用fill（memset函数）

int main()
{
    int L,n;
    scanf("%d %d",&L,&n);
    int road[L+1];
    memset(road,-1,sizeof(road));
    int left,right;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&left,&right);
        memset(road+left,0,(right-left+1)*sizeof(int));
    }
    int cnt=0;
    for(int i=0;i<=L;i++)
        if(road[i]==-1)
            cnt++;
    printf("%d",cnt);
}
