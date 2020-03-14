#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//堆的定义：根比左右都大（或小）
//排序树：左根右递增

using namespace std;

void sift(int heap[],int low,int high)  //向下调整堆，区间为[low,high)
{
    int i=low,j=2*low+1; //j为其左孩子，因为下标从0开始
    while(j<high) //左闭右开
    {
        if(heap[j]<heap[j+1]&&j+1<high)//如果右孩子更大，且有右孩子，因为堆是一个完全二叉树，它必须有左孩子
            j++;
        if(heap[j]>heap[i])
        {
            swap(heap[i],heap[j]);
            i=j;  //调整下一层
            j=2*i+1;
        }
        else
            break;
    }
}

void create(int heap[],int n)  //建堆，大根堆是增序
{
    int mid=n/2-1;
    for(int i=mid;i>-1;i--)
        sift(heap,i,n);
}

int main()
{
    int n;
    cin>>n;
    int heap[n];
    for(int i=0;i<n;i++)
        cin>>heap[i];
    create(heap,n);
    //排序部分
    for(int i=0;i<n-1;i++) //最后一个不需要再筛了
    {
        swap(heap[0],heap[n-i-1]);
        sift(heap,0,n-i-1);   //已经筛出去一个，完全二叉树就少一个
    }
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    return 0;
}
