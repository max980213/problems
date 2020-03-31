//一个数如果恰好等于它的各因子(该数本身除外)子和，如：6=3+2+1。则称其为“完数”；若因子之和大于该数，则称其为“盈数”。 求出2到60之间所有“完数”和“盈数”。



//题目理解错误，是所有的因子，不仅是质因子
//格式真讨厌

#include <stdio.h>
#include <vector>

using namespace std;

int sumfactor(int n)
{
    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        if(n%i==0)
            ans+=i;
    }
    return ans;
}

int main()
{
    vector <int> v1;
    vector <int> v2;
    for(int i=2;i<=60;i++)
    {
        if(i==sumfactor(i))
            v1.push_back(i);
        else if(i<sumfactor(i))
            v2.push_back(i);
    }
    printf("E: ");
    for(int i=0;i<v1.size();i++)
        printf("%d ",v1[i]);
    printf("\nG: ");
    for(int i=0;i<v2.size();i++)
        printf("%d ",v2[i]);
    return 0;
}
