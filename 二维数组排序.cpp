//题目描述：对二维数组进行排序
//要求：每一行顺序递增，i>1时第i行中的任意元素均不小于i-1行的任意元素

//思路：开一个M*N的数组，对整体进行排序，再放回去

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;



int main()
{
    int M,N;
    cin>>M>>N;
    int A[M][N];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        cin>>A[i][j];
    //sort(A,M,N);

        int temp[M*N],num=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            temp[num++]=A[i][j];  //读入

    for(int i=num-1;i>0;i--)
        for(int j=0;j<i;j++)
            if(temp[j+1]<temp[j])
                swap(temp[j],temp[j+1]);  //冒泡排序最好写

    for(int i=M-1;i>=0;i--)
        for(int j=N-1;j>=0;j--)
            A[i][j]=temp[--num];

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

}
