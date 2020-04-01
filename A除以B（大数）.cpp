#include <iostream>
#include <string>

using namespace std;

//模拟竖式除法，用字符串读入

int main()
{
    string a;
    int b;
    cin>>a>>b;
    int left=a[0]-'0';
    for(int i=1;i<a.size();i++)
    {
        left=left*10+a[i]-'0';
        cout<<left/b;
        left%=b;
    }
    cout<<" "<<left;
    return 0;
}
