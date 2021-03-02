//
//  main.c
//  Priority Queue
//
//  Created by Aditya Vikram on 5/3/20.
//  Copyright © 2020 Vikram. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int process;
    int priority;
}sp;

typedef struct node
{
    sp d;
    struct node* next;
}n;

typedef struct queue
{
    n* front;
    n* rear;
}sq;

void initqueue(sq* q)
{
    q->front=NULL;
    q->rear=NULL;
}

void enqueue(sq *q,sp e)
{
    n * p = (n*) malloc (sizeof (n) );
    p->d.process = e.process;
    p->d.priority=e.priority;
    p->next = NULL;
    
    if (! q->front)
        q->front = q->rear = p;
    
    else
    {
        n* cur = q->front;
        n* prev = NULL;
        
        while (cur && e.priority > cur->d.priority)
        {
            prev = cur;
            cur = cur->next;
        }
        
        if(prev)
            prev->next=p;
        
        if(!prev)
            q->front = p;
        
        p->next = cur;
        
        if(! cur)
            q->rear = p;
    }
    
}

sp dequeue(sq* q)
{
    n*p = q->front;
    sp e;
    e.process=p->d.process;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
        q->front=p->next;
    free(p);
    return e;
}

int isempty(sq*q)
{
    return  q->front==NULL;
}

void display(sq *q)
{
    struct node *p = q->front;
    while(p)
    {
        printf("%d\n",p->d.process);
        p=p->next;
    }
}

sp getfront(sq*q)
{
    return q->front->d;
}

void input(sp*e)
{
    scanf("%d",&e->process);
    scanf("%d",&e->priority);
}

/*
int main()
{
    sq q;
    sp p;
    initqueue(&q);
    int ch;
    while(1)
    {
        printf("1. EnQueue \n");
        printf("2. DeQueue \n");
        printf("3. get Front \n");
        printf("4. Display \n");
        printf("5. Size\n");
        printf("6. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter data & priority: ");
                    input(&p);
                    EnQueue(&q,p);
                
                break;


            case 2: if(isQEmpty(&q))
                    printf("Queue is Empty \n");
                else
                {
                    p = DeQueue(&q);
                    printf("%d\n",p.process);
                }
                break;


            case 3:  if(isQEmpty(&q))
                    printf("Queue is Empty \n");
                else
                {
                    p= getFront(&q);
                    printf("%d\n",p.process);
                }
                break;

            case 4: display(&q);
                break;
            case 6: exit(0);


        }
    }
}
*/
