#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}n;

n* getnode(n* p,int e)
{
    p=(n*)malloc(sizeof(n));
    p->val=e;
    return p;
}

void addfront(n** head, int e)
{
    n* p=NULL;
    p=getnode(p,e);
    p->next=*head;
    *head=p;
}

void addrear(n** head,int e)
{
    n* p=NULL;
    p=getnode(p,e);
    p->next=NULL;
    if(*head==NULL)
        *head=p;
    else
    {
    n* cur=*head;
    while((cur->next))
    {
        cur=cur->next;
    }
    cur->next=p;
    }
}

int size(n* head)
{
    n* cur=head;
    int c=0;
    while(cur)
    {
        c++;
        cur=cur->next;
    }
    return c;
}

int deletefront(n** head)
{
    n*p=*head;
    *head=p->next;
    int e=p->val;
    free(p);
    return e;
}

int deleterear(n** head)
{
    int e;
    n* cur=*head;
    n* prev=NULL;
    while(cur->next)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev)
        prev->next=NULL;
    else
        *head=NULL;
    e=cur->val;;
    free(cur);
    return e;
}

int addpos(n**head, int pos, int e)
{
    n*p=NULL;
    n*prev=NULL;
    p=getnode(p,e);
    p->next=NULL;
    n* cur=*head;
    if(!*head || pos<=0)
    {
        p->next=*head;
        *head=p;
    }
    else
    {
        for(int i=0;i<pos && cur;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=p;
        p->next=cur;
    }
    return 0;
}

int deletepos(n**head, int pos)
{
    n* prev=NULL;
    n* cur=*head;
    int e;
    if(!(*head)->next || pos<=0)
    {
        *head=cur->next;
    }
    else
    {
        for(int i=0;i<pos && cur->next;i++)
        {
            prev=cur;
            cur=cur->next;
        }
    prev->next=cur->next;
    }
    e=cur->val;
    free(cur);
    return e;
}

int search(n* head,int key)
{
    n*cur=head;
    while(cur)
    {
        if(cur->val==key)
            return 1;
        cur=cur->next;
    }
    return 0;
}

int display(n* head)
{
    n* cur;
    cur=head;
    while(cur)
    {
        printf("%d\n",cur->val);
        cur=cur->next;
    }
    return 0;
}

