#include <iostream>
#include <map>

using namespace std;

int main()
{
    int A[10]={1,1,2,2,3,3,4,5,14,98};
    map <int,int> mp;
    for(int i=0;i<10;i++)
    {
        if(mp[A[i]])   //原来不存在的元素映射会被默认为0！char的0是空格！
        {
            mp[A[i]]++;
        }
        else
        {
            //cout<<mp[A[i]]<<endl;
            mp[A[i]]=1;
        }

    }

    map<int,int>::iterator it=mp.begin();
    while(it!=mp.end())
    {
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
}
