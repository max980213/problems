/*题目描述
    对于一个十进制数A，将A转换为二进制数，然后按位逆序排列，
    再转换为十进制数B，我们称B为A的二进制逆序数。     
    例如对于十进制数173，它的二进制形式为10101101，
    逆序排列得到10110101，其十进制数为181，181即为173的二进制逆序数。
    
    */
    
    
    
   
//这只是位数int能放下的情况，大数要用数组存

#include <stdio.h>
#include <queue>

using namespace std;

//看用例才知道这个数超级大
//又要用大数存储

int main()
{
    int n;
    scanf("%d",&n);
    //逆序可直接用栈
    queue <int> q;
    while(n!=0)
    {
        q.push(n%2);
        n/=2;
    }
    int ans=0;
    while(!q.empty())
    {
        ans=ans*2+q.front();
        q.pop();
    }
    printf("%d",ans);
    return 0;
}
