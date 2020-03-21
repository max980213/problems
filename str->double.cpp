//题目描述：将输入的字符串转化为一个数，若可转换则比较大小，大返回true
//不可转或小于等于均返回0
//-3.114   a.3  3a.7均不可转

#include <string>
#include <iostream>

using namespace std;

bool cmp(string num,double x)
{
    double ans=0;
    int flag=0;//flag用来标记是否进入小数位
    double carry=0.1;  //用于小数进位
    double temp=0;
    for(int i=0;i<num.size();i++)
    {
        if((num[i]<'0'||num[i]>'9')&&num[i]!='.')
            return 0;
        if(num[i]!='.'&&flag==0)
            ans=ans*10+num[i]-'0';
        else if(num[i]=='.')
        {
            flag=1;
        }
        else
        {
            temp+=(num[i]-'0')*carry;
            carry*=carry;
        }
    }
    ans+=temp;
    return ans>x;
}

int main()
{
    string num;
    cin>>num;
    double x;
    cin>>x;
    cout<<cmp(num,x);
}
