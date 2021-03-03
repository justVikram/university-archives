#include <stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct Queue
{
    int elements [SIZE];
    int front, rear;
}sq;

void initqueue (struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int e)
{
    q->rear = (q->rear + 1) % SIZE;
    q->elements [q->rear] = e;
    
    if (q->front == -1)
        q->front = 0;
}

int dequeue (struct Queue *q)
{
    int e = q->elements [q->front];
    
    if (q->rear == q->front)
        q->rear = q->front = -1;
    
    else
        q->front=(q->front + 1) % SIZE;
    
    return e;
}

int getfront (const struct Queue *q)
{
    return q->elements[q->front];
}


int isempty(const struct Queue *q)
{
    if (q->front == -1)
        return 1;
    
    else
        return 0;
}

int isfull (const struct Queue *q)
{
    if ((q->rear + 1) % SIZE == q->front)
        return 1;
    
    else
        return 0;
}

int qsize (const struct Queue * q)
{
    int s;
    
    if(q->front == -1)
        s=0;
    
    else if (q->rear >= q->front)
        s = q->rear - q->front + 1;
    
    else
        s = SIZE + q->rear - q->front +1;

    return s;
}

void display(const struct Queue *q)
{
    int i;
    
    for(i = q->front; i != q->rear; i = (i + 1) % SIZE)
        printf("%d\n", q->elements[i]);

    if(q->front != -1)
        printf("%d\n", q->elements[i]);
}

