#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int var;
    struct node* next;
}n;

void addfront(n** tail,int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->var=e;
    p->next=p;
    if(!(*tail))
        *tail=p;
    else
    {
        p->next=(*tail)->next;
        (*tail)->next=p;
    }
}

void addrear(n** tail,int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->var=e;
    p->next=p;
    if(!(*tail))
        *tail=p;
    else
    {
        p->next=(*tail)->next;
        (*tail)->next=p;
        *tail=p;
    }
}

int deletefront(n** tail)
{
    n*cur=(*tail)->next;
    int e=cur->var;
    (*tail)->next=cur->next;
    if((*tail)->next==*tail)
        *tail=NULL;
    free(cur);
    return e;
}

int deleterear(n** tail)
{
    n*cur=*tail;
    n*  prev=(*tail)->next;
    int e=cur->var;
    while(prev->next!=cur)
        prev=prev->next;
    prev->next=(*tail)->next;
    *tail=prev;
    if((*tail)->next==*tail)
        *tail=NULL;
    free(cur);
    return e;
}

void addpos(n** tail,int pos, int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->var=e;
    p->next=p;
    if(!(*tail))
        *tail=p;
    else if(pos<=0)
    {
        p->next=(*tail)->next;
        (*tail)->next=p;
    }
    else
    {
        n* cur=(*tail)->next;
        n* prev=NULL;
        for(int i=0;i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
            if(cur==(*tail)->next)
                break;
        }
        prev->next=p;
        p->next=cur;
        if(cur==(*tail)->next)
            *tail=p;
    }
}

int deletepos(n** tail, int pos)
{
    n*cur=(*tail)->next;
    int e=cur->var;
    if(*tail==cur)
    {
        *tail=NULL;
        free(cur);
        return e;
    }
    else if(pos<=0)
    {
        (*tail)->next=cur->next;
        free(cur);
        return e;
    }
    else
    {
        n*prev=NULL;
        for(int i=0;i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
            if(cur==*tail)
                break;
        }
        prev->next=cur->next;
        e=cur->var;
        if(cur==*tail)
            *tail=prev;
        free(cur);
        return e;
    }
}

int size(n* tail)
{
    int c=0;
    if(!tail)
        return c;
    n*cur=tail->next;
    do
    {
        c++;
        cur=cur->next;
    }
    while(cur!=tail->next);
    return c;
}

void display(n* tail)
{
    if(!tail)
        return;
    n*cur=tail->next;
    do
    {
        printf("%d\n",cur->var);
        cur=cur->next;
    }
    while(cur!=tail->next);
}

int search(n* tail,int key)
{
    if(!tail)
        return 0;
    n*cur=tail->next;
    do
    {
        if(cur->var==key)
            return 1;
        cur=cur->next;
    }
    while(cur!=tail->next);
    return 0;
}

void splitalt(n* tail)
{
    n* head=tail->next;
    n*list1=NULL;
    n*list2=NULL;
    n*cur=head;
    for(int i=0;i<size(tail);i++)
    {
        if(i%2)
            addfront(&list1,cur->var);
        else
            addfront(&list2,cur->var);
        cur=cur->next;
    }
    printf("The first list is:\n");
    display(list1);
    printf("The second list is:\n");
    display(list2);
}

void splitpos(n* tail,int pos)
{
    n* head=tail->next;
    n* prev=NULL;
    n* cur=head;
    for(int i=0;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=head;
    tail->next=cur;
    head=prev;
    printf("The first list is:\n");
    display(head);
    printf("The second list is:\n");
    display(tail);
}
