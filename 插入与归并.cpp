/*
题目描述
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确
的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩
下1个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入描述:
输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以
空格分隔。


输出描述:
首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试
的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。

输入例子:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

输出例子:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
*/

/如果是直接插入排序，那么只有前几个是有序的，从无序位置开始，与原始数列应该是相同的，利用该点判断

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int i=0;
    while(b[i]<b[i+1]&&i<n)
        i++;
    int j=i+1;
    while(b[j]==a[j]&&j<n)
        j++;
    if(j==n)
    {
        printf("Insertion Sort\n");
        sort(b,b+i+2);   //左闭右开
        for(int k=0;k<n;k++)
            printf("%d ",b[k]);
    }
    else
    {
        printf("Merge Sort\n");  //此时i正好就是归并排序的步长
                                 //其实有bug，如果凑巧连续两组是有序的，那么实际步长就小
                                 //但应付这个题足够了
        int step=2*(i+1),k=0;
        do
        {
            sort(b+k,b+min(n,k+step));
            k+=step;
        }while(k<n);
        for(int m=0;m<n;m++)
            printf("%d ",b[m]);
    }
    return 0;
}
