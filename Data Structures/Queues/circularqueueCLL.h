#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int var;
    struct node* next;
}n;

typedef struct queue
{
    n* front;
    n* rear;
}sq;

void initqueue(sq *q)
{
    q->front=q->rear=NULL;
}

void enqueue(sq *q,int e)
{
    n*p=(n*)malloc(sizeof(n));
    p->var=e;
    p->next=p;
    if(!(q->front))
        q->front=q->rear=p;
    else
    {
        q->rear->next=p;
        p->next=q->front;
        q->rear=p;
    }
}

int dequeue(sq* q)
{
    n*p=q->front;
    int e=p->var;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
    {
        q->front=q->front->next;
        q->rear->next=q->front;
    }
    free(p);
    return e;
}

int isempty(sq* q)
{
    return q->front==NULL;
}

int size(sq *q)
{
    int c=0;
    n*p=q->front;
    if(!q->front)
        return c;
    do
    {
        c++;
        p=p->next;
    }
    while(p!=q->front);
    return c;
}

int getfront(sq* q)
{
    return q->front->var;
}

void display(sq* q)
{
    n*p=q->front;
    do
    {
        printf("%d\t",p->var);
        p=p->next;
    }
    while(p!=q->front);
    printf("\n");
}
