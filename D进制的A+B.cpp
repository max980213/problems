/*
题目描述
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入描述:
输入在一行中依次给出3个整数A、B和D。


输出描述:
输出A+B的D进制数。

输入例子:
123 456 8

输出例子:
1103
*/

#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int a,b,m;
    scanf("%d %d %d",&a,&b,&m);
    int c=a+b;
    stack <int> st;
    while(c!=0)
    {
        st.push(c%m);
        //printf("%d",c%m);  //我惊了，这样输出是逆序的
        c/=m;
    }
    while(!st.empty())  //不用栈的话，可用递归（深度->栈->递归，广度->队列）
    {
        printf("%d",st.top());
        st.pop();
    }
    return 0;
}
