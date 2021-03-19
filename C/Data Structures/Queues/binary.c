#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct Queue
{
	struct node *front;
	struct node *rear;
};

void initQueue(struct Queue *);
void EnQueue(struct Queue *, int);
int DeQueue(struct Queue *);
int isQEmpty(const struct Queue *);
void binary(int);

int main()
{
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	binary(N);
	return 0;
}

void binary(int N)
{
	struct Queue q;
	initQueue(&q);
	int i, e;
	EnQueue(&q, 1);
	for(i=1;i<=N;i++)
	{
		e = DeQueue(&q);
		printf("%d\n",e);
		EnQueue(&q, e*10);
		EnQueue(&q, e*10+1);
	}
	while(!isQEmpty(&q))
		DeQueue(&q);
}



void initQueue(struct Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}


void EnQueue(struct Queue *q, int e)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data = e;
	p->next = NULL;

	struct node *prev=NULL;
	struct node *cur = q->front;

	if(p==NULL)
	{
		printf("Memory Full\n");
		return;
	}
	if(q->rear==NULL)
		q->rear = q->front = p;
	else
	{
		q->rear->next =p;
		q->rear = p;
	}
}


int DeQueue(struct Queue *q)
{
	int e = q->front->data;

	struct node *p = q->front;

	q->front = p->next;

	if(q->front==NULL)
		q->rear = NULL;

	free(p);

	return e;
}

int isQEmpty(const struct Queue *q)
{
	if(q->front==NULL)
		return 1;
	else
		return 0;
}

