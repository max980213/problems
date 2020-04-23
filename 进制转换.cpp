#include <stdio.h>
#include <stack>
 
using namespace std;
 
int main()
{
    char num[16];//最大只有16进制，按照题设
    for(int i=0;i<16;i++)
    {
        if(i>9)
            num[i]='A'+i-10;
        else
            num[i]='0'+i;
    }
    int n,R;
    stack <char> st;
    while(scanf("%d %d",&n,&R)!=EOF)
    {
        while(n!=0)
        {
            st.push(num[n%R]);
            n/=R;
        }
        while(!st.empty())
        {
            printf("%c",st.top());
            st.pop();
        }
        printf("\n");
    }
    return 0;
}
