/*
题目描述
如果一个数字从左边读和从右边读一样，那么这个数字就是一个回文数。例如32123就是一个回文数；17在某种意义上也是一个回文数，因为它的二进制型式——10001——是一个回文数。
请你帮忙开发一个程序，判断一个数n在任意进制（2-16）下是否有回文数。

输入描述:
输入包含多组数据。
每组数据包括一个正整数n (1≤n<2^31)。


输出描述:
对应每组数据，如果n在2-16进制下存在回文数，则输出“Yes”；否则输出“No”。

输入例子:
32123
17

输出例子:
Yes
Yes
*/

#include <stdio.h>
#include <vector>

using namespace std;

bool isok(int n)
{
    for(int i=2;i<=16;i++)
    {
        vector <int> vi;
        vi.clear();
        int temp=n,flag=1;
        while(temp!=0)
        {
            vi.push_back(temp%i);
            temp/=i;
        }
        int k=0,j=vi.size()-1;
        while(k<j)
        {
            if(vi[k++]!=vi[j--])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(isok(n))
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
