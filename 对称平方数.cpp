//打印所有不超过n（n<256）的，其平方具有对称性质的数。如11*11=121。

#include <stdio.h>
#include <vector>
#include <algorithm>  //reverse()

using namespace std;

/*bool issymmetry(int n)
{
    vector <int> vi;
    while(n!=0)
    {
        vi.push_back(n%10);
        n/=10;
    }
    vector <int> temp=vi;
    reverse(vi.begin(),vi.end());
    for(int i=0;i<vi.size();i++)
    {
        if(vi[i]!=temp[i])
            return 0;
    }
    return 1;
}
*/

int rev(int n)    //非常快的更好方法
{
    int ans=0;
    while(n!=0)
    {
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}

int main()
{
    for(int i=1;i<256;i++)
    {
        if((i*i)==rev(i*i))
            printf("%d\n",i);
    }
    return 0;
}
