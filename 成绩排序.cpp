/*
题目描述
查找和排序

题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。

示例：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

jack      70
Tom      70
peter     96

输入描述:
输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开

输出描述:
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

*/



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct node
{
    string name;
    int grades;
}node;

bool cmp0(node a,node b)
{
    return a.grades>b.grades;
}

bool cmp1(node a,node b)
{
    return a.grades<b.grades;
}

int main()
{
    int n;
    cin>>n;
    node stu[n];
    int flag;
    cin>>flag;
    for(int i=0;i<n;i++)
    {
        node temp;
        cin>>temp.name>>temp.grades;
        stu[i]=temp;
    }
    if(flag==0)
        stable_sort(stu,stu+n,cmp0);
    else
        stable_sort(stu,stu+n,cmp1);
    for(int i=0;i<n;i++)
        cout<<stu[i].name<<" "<<stu[i].grades<<endl;
    return 0;
}
