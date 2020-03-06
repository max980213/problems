/*题目描述：
对于一副扑克牌，我们有多种不同的洗牌方式。一种方法是从中间某个位置分成两半，然后相交换，我们称之为移位（shift）。
比如原来的次序是123456，从第4个位置交换，结果就是561234。
这个方式其实就是数组的循环移位，为了多次进行这个操作，必须使用一种尽可能快的方法来编程实现。
在本题目中，还引入另外一种洗牌方式，就是把前一半（如果总数是奇数，就是(n-1)/2）牌翻转过来，这种操作称之为翻转（flip）。
在前面shift操作的结果上进行flip，结果就是165234。当然，如果是实际的扑克牌，直接翻转会造成正反面混在一起的，我们就不管那么多了。 
给定n张牌，初始次序为从1到n，经过若干次的shift和flip操作后，结果会是什么样？
输入包括多组测试数据，每组数据的第一行包括两个数 n和k。
n表示牌的数目，1<n<1000，k表示下面要进行的操作数量。
随后的k行，每行一个整数x，1<=x<=n，表示从第几个位置开始移位。
在每一次shift操作后都接一个flip操作。
最后输出数组。
*/

//思想：部分移位可用3次逆序实现，但要注意第2、3次逆序的区间



#include <stdio.h>
#include <stdlib.h>

//左右均为闭区间

void reverse(int ans[],int left,int right)
{
    int temp;
    int i=left,j=right;
    for(int k=0;k<(right-left)/2+1;k++)
    {
        temp=ans[i];
        ans[i++]=ans[j];
        ans[j--]=temp;

    }
}

void shift(int ans[],int n,int m)
{
    reverse(ans,0,n-1);
    reverse(ans,0,n-m-1);
    reverse(ans,n-m,n-1);
}

void flip(int ans[],int n)
{
    int mid=n/2;
    reverse(ans,0,mid-1);
}


int main()
{
    int n,k;
    //scanf("%d %d",&n,&k);
    n=6;
    k=1;
    int ans[n]={1,2,3,4,5,6};
    int m;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&m);
        shift(ans,n,m);
        flip(ans,n);
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
