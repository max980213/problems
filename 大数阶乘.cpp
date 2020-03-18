//大数存储

#include <iostream>

int num[3000]={0};

using namespace std;

int main()
{
    int n;
    cin>>n;
    num[0]=1;
    int step=1;//当前位数
    for(int i=2;i<=n;i++)
    {
        int carry=0; //进位初始化为0
        for(int j=0;j<step;j++)
        {
            num[j]=num[j]*i+carry;
            if(num[j]>9)
            {
                carry=num[j]/10;  //这一步应该在前面，不然num[j]会被覆盖
                num[j]=num[j]%10;
            }
            else
                carry=0;  //该次运算进位为0
        }
        while(carry!=0) //最高位进位
        {
            num[step++]=carry%10;
            carry/=10;
        }
    }
    for(int i=step-1;i>-1;i--)
        cout<<num[i];
    return 0;
}
