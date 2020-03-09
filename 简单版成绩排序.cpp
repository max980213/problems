/*

题目描述
用一维数组存储学号和成绩，然后，按成绩排序输出。
输入描述:
输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。
接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
输出描述:
按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
如果学生的成绩相同，则按照学号的大小进行从小到大排序。

*/

include <iostream>
#include <algorithm>

using namespace std;

typedef struct node
{
    int id;
    int score;
}node;

bool cmp(node a,node b)
{
    if(a.score==b.score)
        return a.id<b.id;
    else
        return a.score<b.score;
}


void sorttt(node a[],int n)  //未防止老用sort函数忘了排序怎么排
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j].score>a[j+1].score)
                swap(a[j],a[j+1]);
            else if(a[j].score==a[j+1].score)
            {
                if(a[j].id>a[j+1].id)
                {
                    swap(a[j],a[j+1]);
                }
            }
        }
    }
}



int main()
{
    int n;
    cin>>n;
    node a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].id>>a[i].score;
    }
  //  sort(a,a+n,cmp);
    sorttt(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].id<<" "<<a[i].score<<endl;
    }
    return 0;
}
