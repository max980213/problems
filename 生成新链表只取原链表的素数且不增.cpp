#include <stdio.h>

typedef struct node
{
    int data;
    node *next;
}node;

node* create(node* head,int n)
{
    for(int i=0;i<n;i++)
    {
        node *in=new node;
        in->next=head->next;
        head->next=in;
        scanf("%d",&in->data);
    }
    return head;
}

bool isprime(int x)
{
    if(x==0||x==1)
        return 0;
    int i=2;
    while(i*i<=x)
    {
        if(x%i==0)
            return 0;
        i++;
    }
    return 1;
}

node* change(node* head)
{
    node *newhead=new node;
    newhead->next=NULL;
    node *temp=head->next;
    while(temp!=NULL)
    {
        int x=temp->data;
        if(x<0)
            x=(-x);
        if(isprime(x))
        {
            node *p=newhead,*q=newhead->next;
            while(q!=NULL)
            {
                if(temp->data<q->data)
                {
                    p=q;
                    q=q->next;
                }
            }
            node *in=new node;
            in->data=temp->data;
            in->next=q;
            p->next=in;
        }
        temp=temp->next;
    }
    return newhead;
}


int main()
{
    node *head=new node;
    head->next=NULL;
    head=create(head,7);
    node *newhead=change(head);
    node *temp=newhead->next;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
