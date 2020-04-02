/*
题目描述
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为
3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入描述:
每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的
子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。


输出描述:
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入例子:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出例子:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/





//考虑使用map   k/N即需要反转的次数
//但是设计3个量，故改使用结构体
//于是变成了一个静态链表
//实现逆序可以使用头插法，以100000为头结点
 
#include <stdio.h>
 
#define maxn 100001  //已知地址均为5位数
 
typedef struct node
{
    int data;
    int next;
}node;
 
int reverse(node list[],int head,int k) //头插法，返回下一次反转的头结点，即本次的尾
{
    int temp,tail=list[head].next; //经头插法后，该节点一定是尾结点
    //int i,j;
    for(int i=list[list[head].next].next,j=0;i!=-1&&j<k-1;j++)  //直接从第二个结点开始头插
    {                                   //查阅资料，如果for中需要声明两个变量，只可以是一个int，不可两个int，且前后类型必须相同
        temp=list[i].next;              //如果不同的话，只能放到外面去声明了
        list[i].next=list[head].next;
        list[head].next=i;
        list[tail].next=temp;
        i=temp;
    }
    return tail;
}  //事实上，可以先遍历，找到最后一个结点，令head->next=tail，再进行插入
 
int main()
{
    node list[maxn];
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    int head=100000;
    list[head].next=start; //头结点
    int add;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&add);
        scanf("%d %d",&list[add].data,&list[add].next);
    }
 
    int cnt=0;
 
    for(int i=head;list[i].next!=-1;i=list[i].next)
    {
        cnt++; //统计有效结点个数
    }
 
    for(int j=cnt/k,i=head;j>0&&i!=-1;j--)  //需要反转cnt/k次，最后一次若不够不需反转
    {
        i=reverse(list,i,k);
    }
    for(int i=list[head].next;i!=-1;i=list[i].next)
    {
        if(list[i].next!=-1)
            printf("%05d %d %05d\n",i,list[i].data,list[i].next);
        else
            printf("%05d %d %d\n",i,list[i].data,list[i].next);
    }
    return 0;
}
