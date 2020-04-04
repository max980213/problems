#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int a,b,m;
    scanf("%d %d %d",&a,&b,&m);
    int c=a+b;
    if(c==0)
    {
        printf("0");
        return 0;
    }
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
