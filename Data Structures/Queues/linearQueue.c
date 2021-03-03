#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct Queue
{
	int elements[SIZE];
	int front, rear;
};

void initQueue(struct Queue *);
void EnQueue(struct Queue *, int);
int DeQueue(struct Queue *);
int getFront(const struct Queue *);
int isQEmpty(const struct Queue *);
int isQFull(const struct Queue *);
int Qsize(const struct Queue *);
void display(const struct Queue *);


int main()
{
	struct Queue q;
	initQueue(&q);
	int ch, e, y;
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
			case 1: if(isQFull(&q))
					printf("Queue is Full\n");
				else
				{
					printf("Enter data:");
					scanf("%d",&e);
					EnQueue(&q, e);
				}
				break;


			case 2: if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = DeQueue(&q);
					printf("%d\n",e);
				}
				break;


			case 3:  if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = getFront(&q);
					printf("%d\n",e);
				}
				break;

			case 4: display(&q);
				break;

			case 5: y = Qsize(&q);
				printf("size of queue = %d\n",y);
				break;

			case 6: exit(0);


		}
	}
}



void initQueue(struct Queue *q)
{
	q->front = 0;
	q->rear = -1;
}


void EnQueue(struct Queue *q, int e)
{
	q->rear++;
	q->elements[q->rear]=e;
}


int DeQueue(struct Queue *q)
{
	int e = q->elements[q->front];
	q->front++;
	return e;
}


int getFront(const struct Queue *q)
{
	return q->elements[q->front];
}


int isQEmpty(const struct Queue *q)
{
	if(q->front>q->rear)
		return 1;
	else
		return 0;
}


int isQFull(const struct Queue *q)
{
	if(q->rear==SIZE-1)
		return 1;
	else
		return 0;
}


int Qsize(const struct Queue *q)
{
	return q->rear - q->front + 1;
}

void display(const struct Queue *q)
{
	int i;
	for(i=q->front;i<=q->rear;i++)
		printf("%d\n",q->elements[i]);
}

