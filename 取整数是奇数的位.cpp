//将整型S的每一位中的奇数取出，作为一个新的数
//如987312，返回9731


#include <stdio.h>

int change(int S)
{
    int carry=1;
    int temp;
    int ans=0;
    while(S!=0)
    {
        temp=S%10;
        if(temp%2==1) //该位是奇数
        {
            ans=ans+temp*carry;
            carry*=10;
        }
        S/=10;
    }
    return ans;
}

int main()
{
    int S;
    scanf("%d",&S);
    printf("%d",change(S));
    return 0;
}

