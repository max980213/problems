/*

#include<stdio.h>
int main(){
     int n,e,flag=0;
     while(scanf("%d%d",&n,&e)==2){
         if(n*e){
             if(flag)
                 printf(" ");
             else
                 flag=1;
             printf("%d %d",n*e,e-1);
         }
     }
     if(!flag)
         printf("0 0");
  
}
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vi;
    int n;
    while(cin>>n)
        vi.push_back(n);
    for(unsigned int i=1;i<vi.size();i+=2)
    {
        if(vi[i]==0)
        {   if(vi.size()==2)
                cout<<"0 0";
            else
                cout<<0;
        }
        else if(vi[i]==1)
        {
            cout<<vi[i-1];
        }
        else
        {
            vi[i-1]*=vi[i];
            vi[i]--;
            cout<<vi[i-1]<<" "<<vi[i];
        }
        if(i!=vi.size()-1)
            cout<<' ';
    }
    return 0;
}
