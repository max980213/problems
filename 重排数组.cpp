//在O(n)内重排数组，要求负在前正在后
//非常容易的快排思想

#include <iostream>
#include <algorithm>

using namespace std;

void sort(int a[],int left,int right)
{
    int i=left,j=right;
    while(i!=j)
    {
        while(i!=j&&a[i]<0)
            i++;
        while(i!=j&&a[j]>=0)
            j--;
        swap(a[i],a[j]);
    }
}

int main()
{
    int a[10]={0,-1,2,-3,4,-5,6,-7,8,-9};
    sort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}
