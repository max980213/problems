/*
题目描述
N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。
现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。
帽子的颜色用“red”，“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
输入描述:
多案例输入，每个案例的输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于100的正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。

注意：白鼠的重量各不相同
*/

#include <algorithm>
#include <iostream>

using namespace std;

typedef struct mouse
{
    string color;
    int weight;
}mouse;

bool cmp(mouse a,mouse b)
{
    return a.weight>b.weight;
}

int main()
{
    int n;
    cin>>n;
    mouse a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].weight>>a[i].color;
    }
    
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        cout<<a[i].color<<endl;
    return 0;
    
}
