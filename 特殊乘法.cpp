//对2个小于1000000000的输入，求结果。 特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    vector <int> ai;
    vector <int> bi;
    while(a!=0)
    {
        int temp=a%10;
        ai.push_back(temp);
        a/=10;
    }
    while(b!=0)
    {
        int temp=b%10;
        bi.push_back(temp);
        b/=10;
    }
    int ans=0;
    for(int i=0;i<ai.size();i++)
    {
        for(int j=0;j<bi.size();j++)
        {
            ans+=ai[i]*bi[j];
        }
    }
    cout<<ans;
}
