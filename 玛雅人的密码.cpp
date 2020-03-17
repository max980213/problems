/*
题目描述
玛雅人有一种密码，如果字符串中出现连续的2012四个数字就能解开密码。
给一个长度为N的字符串，（2=<N<=13）该字符串中只含有0,1,2三种数字，问这个字符串要移位几次才能解开密码，每次只能移动相邻的两个数字。
例如02120经过一次移位，可以得到20120,01220,02210,02102，其中20120符合要求，因此输出为1.如果无论移位多少次都解不开密码，输出-1。
*/


//利用BFS

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
//#include <map>

using namespace std;

bool iscode(string str,int n)
{
    for(int i=0;i<n-3;i++)
    {
        if(str[i]!='2')
            continue;
        else if(str[i+1]!='0')
            continue;
        else if(str[i+2]!='1')
            continue;
        else if(str[i+3]!='2')
            continue;
        else
            return 1;
    }
    return 0;
}

int str2int(string str,int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp=temp*3+(str[i]-'0');  //只有0，1，2，看成3进制
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;
    int t=1;
    for(int i=0;i<n;i++)
        t*=3;   //3进制
    int dis[t];
    fill(dis,dis+t,-1);
    string temp;
    cin>>temp;
    queue<string> q;
    q.push(temp);
    dis[str2int(temp,n)]++;
    while(!q.empty())
    {
        temp=q.front();
        if(iscode(temp,n))
        {
            cout<<dis[str2int(temp,n)];
            return 0;
        }
        q.pop();
        int num=str2int(temp,n);
        for(int i=0;i<n-1;i++)
        {
            string flag=temp;
            swap(flag[i],flag[i+1]);
            int seq=str2int(flag,n);
            if(dis[seq]==-1)
            {
                q.push(flag);
                dis[seq]=dis[num]+1;
            }
        }
    }
    cout<<-1;
    return 0;
}
