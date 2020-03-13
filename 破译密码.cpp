/*
题目描述：输入两个字符串，需要破译的密码是从s1到s2的变换的最小次数
两个字符串长度均为4，对s1，每次任选一个位置，对剩下的3个位置从小到大依+2、+3、+5，若超出z则重新从a开始
找不到返回-1
*/

#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node   //可不设置结构体，可以直接在26^4数组上作文章，为0表示没访问过，然后数组元素值逐层加1
{                     //故应设置int型而非bool型，最后该数组str2对应位置的值即是结果
    char str[5];
    int layer; //记录层数
}node;

bool isequal(char a[],char b[])
{
    for(int i=0;i<4;i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

int f(char a[])
{
    int temp=0;
    for(int i=0;i<4;i++)
    {
        temp=temp*26+a[i]-'a';
    }
    return temp;
}

node change(node a,int i)  //有更简洁的写法
{
    int addnum[3]={2,3,5};
    int cnt=0;
    node temp;
    temp.layer=a.layer+1;
    for(int k=0;k<4;k++)
    {
        if(k!=i)
        {
            temp.str[k]=(a.str[k]+addnum[cnt++]-'a')%26+'a';
        }
        else
            temp.str[k]=a.str[i];
    }
    return temp;
}


int main()
{
    bool vis[26*26*26*26];
    fill(vis,vis+26*26*26*26,0);
    node str1;
    str1.layer=0;
    char str2[5];
    cin>>str1.str>>str2;
    queue <node> q;
    q.push(str1);
    vis[f(str1.str)]=1;  //标记已访问
    //int layer=1; //层数
    while(!q.empty())
    {
        node temp=q.front();
        if(isequal(temp.str,str2))
        {
            cout<<temp.layer;
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            node flag=change(temp,i);
            int mark=f(flag.str);
            if(!vis[mark])   //为访问过
            {
                q.push(flag);
                vis[mark]=1;
            }
        }
    }
    cout<<-1;
    return 0;
}



