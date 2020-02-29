#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

//两两交换链表结点的超级代码，是真的交换结点，不只是交换值

node* swap(node *head)
{
    node **p=&head,*a,*b;  //二层指针，p==&head,*p==head,**p==*head
    while((a=*p)&&(b=a->next))
    {
        a->next=b->next;  //勾链
        b->next=a;
        *p=b;   //第一次更新head，第二次以后实际上是更新上一个a结点的a->next
        p=&(a->next); //更新p
    }
    return head;
}


int main ()
{
    //
}
