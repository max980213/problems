//题目描述：链表中原有的结点，两两之间插入一个新结点

#include <stdio.h>

typedef struct node
{
    int data;
    node* next;
}node;

void insert(node *head)
{
    if(head==NULL)
        return;
    node *p=head->next;
    node *q=p->next;
    while(p!=NULL&&q!=NULL)
    {
        node *temp=new node;
        temp->next=q;
        p->next=temp;
        p=q;
        q=q->next;
    }
}  //q不必要

int main()
{
    //
}
