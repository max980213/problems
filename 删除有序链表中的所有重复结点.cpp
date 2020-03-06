//如：输入 1 2 3 3 4 4 5输出1 2 5


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn=1010;

typedef struct node
{
    int data;
    node *next;
}node;

int main()
{
    int n;
    scanf("%d",&n);
    node *head=(node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    node *p=head;
    for(int i=0;i<n;i++)
    {
        p->next=(node*)malloc(sizeof(node));
        scanf("%d",&p->next->data);
        p->next->next=NULL;
        head->data++;
        p=p->next;
    }
    node *last=head;
    node *temp=head->next;
    p=temp->next;
    while(temp!=NULL&&temp->next!=NULL)
    {
        if(temp->data==p->data)
        {
            while(temp->data==p->data)
            {
                node *q=temp;
                last->next=p;
                free(q);
                head->data--;
                temp=p;
                p=p->next;
            }
            free(temp);
            head->data--;
            last->next=p;
            temp=p;
            p=p->next;
        }
        else
        {
            last=temp;
            temp=p;
            p=p->next;
        }
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);   //第一个输出的是头结点的数据域，意义为结点个数
        head=head->next;
    }
    return 0;
}
