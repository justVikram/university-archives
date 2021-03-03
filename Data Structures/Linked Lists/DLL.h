#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int var;
    struct node* next;
    struct node* prev;
}n;

void addfront(n** head, int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->prev=NULL;
    p->next=NULL;
    p->var=e;
    if(*head)
    {
        p->next=*head;
        (*head)->prev=p;
    }
    *head=p;
}

void addrear(n** head,int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->var=e;
    p->next=NULL;
    p->prev=NULL;
    if(*head)
    {
        n*cur=*head;
        while(cur->next)
            cur=cur->next;
        cur->next=p;
        p->prev=cur;
    }
    else
        *head=p;
}

int deletefront(n** head)
{
    n*cur=*head;
    *head=(*head)->next;
    if(*head)
    (*head)->prev=NULL;
    int e=cur->var;
    free(cur);
    return e;
}

int deleterear(n** head)
{
    n*cur=*head;
    while(cur->next)
        cur=cur->next;
    int e=cur->var;
    if(cur->prev)
    cur->prev->next=NULL;
    else
        *head=NULL;
    free(cur);
    return e;
}

void addpos(n** head, int pos,int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->prev=p->next=NULL;
    p->var=e;
    if(!(*head))
        *head=p;
    else if(pos<=0)
    {
        p->next=*head;
        (*head)->prev=p;
        *head=p;
    }
    else
    {
        n*cur=*head;
        n*follow=NULL;
        for(int i=0;i<pos && cur;i++)
        {
            follow=cur;
            cur=cur->next;
        }
        follow->next=p;
        p->prev=follow;
        p->next=cur;
        if(cur)
        cur->prev=p;
    }
    
}

int deletepos(n** head,int pos)
{
    n*cur=*head;
    int e=cur->var;
    if(!(*head)->next)
    {
        *head=NULL;
        free(cur);
        return e;
    }
    else if(pos<=0)
    {
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(cur);
        return e;
    }
    else
    {
        for(int i=0;i<pos && cur->next;i++)
            cur=cur->next;
        cur->prev->next=cur->next;
        e=cur->var;
        free(cur);
        return e;
    }
}

void display(n* head)
{
    if(!head)
        return;
    else
    {
        n*cur=head;
        while(cur)
        {
            printf("%d\n",cur->var);
            cur=cur->next;
        }
    }
}

int size(n* head)
{
    int c=0;
    if(!head)
        return 0;
    else
    {
        n*cur=head;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        return c;
    }
}

int search(n* head, int key)
{
    if(!head)
        return 0;
    else
    {
        n*cur=head;
        while(cur)
        {
            if(key==cur->var)
                return 1;
            cur=cur->next;
        }
    }
        return 0;
}
