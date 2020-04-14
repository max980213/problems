#include <stdio.h>
 
int gcd(int x,int y)  //求最大公约数
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
 
void add(int a1,int a2,int b1,int b2)
{
    int n1=a1*b2+a2*b1;
    int n2=a2*b2;
    int temp=gcd(n1,n2);
    if(temp<0)
        temp=-temp;
    printf("%d/%d\n",n1/temp,n2/temp);
}
 
void mul(int a1,int a2,int b1,int b2)
{
    int n1=a1*b1;
    int n2=a2*b2;
    int temp=gcd(n1,n2);
    if(temp<0)
        temp=-temp;
    printf("%d/%d\n",n1/temp,n2/temp);
}
 
int main()
{
    int a1,a2,b1,b2;   //第一个数和第二个数得分子和分母
    char ch;
    while(scanf("%d/%d %d/%d %c",&a1,&a2,&b1,&b2,&ch)!=EOF)
    {
        //printf("%d %d %d %d\n",a1,a2,b1,b2);
        switch(ch)
        {
            case '+':
                {
                    add(a1,a2,b1,b2);
                    break;
                }
            case '-':
                {
                    add(a1,a2,-b1,b2);
                    break;
                }
            case '*':
                {
                    mul(a1,a2,b1,b2);
                    break;
                }
            case '/':
                {
                    mul(a1,a2,b2,b1);
                    break;
                }
        }
    }
    return 0;
}
