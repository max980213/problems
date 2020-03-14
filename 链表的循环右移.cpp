#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node *next;
}node;

int main()
{
    node *head=new node;
    head->data=0;
    head->next=NULL;

    node *q=head;

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        node *temp=new node;
        scanf("%d",&temp->data);
        temp->next=q->next;
        q->next=temp;
        q=temp;
        head->data++;
    }
    //此时q指向链表最后一个结点，实现链表循环右移，利用for循环
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)  //复杂度为n^2的方法：每次都遍历，找到前驱结点，可以开指针数组，在插入结点的时候就把要移位的存进来，空间换时间
    {
        node *temp=head;
        while(temp->next!=q)
        {
            temp=temp->next;
        }
        temp->next=q->next;
        q->next=head->next;
        head->next=q;
        q=temp; //更新q到新的最后一个结点上
    }
    for(head;head!=NULL;head=head->next)
        printf("%d ",head->data);
    return 0;
}
