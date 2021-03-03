#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct Queue
{
	int elements[SIZE];
	int front, rear;
};

void initQueue(struct Queue *);
void EnQueueRear(struct Queue *, int);
void EnQueueFront(struct Queue *, int);
int DeQueueFront(struct Queue *);
int DeQueueRear(struct Queue *);
int getFront(const struct Queue *);
int getRear(const struct Queue *);
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
		printf("1. EnQueue Rear\n");
		printf("2. EnQueue Rear\n");
		printf("3. DeQueue Front\n");
		printf("4. DeQueue Rear\n");
		printf("5. get Front \n");
		printf("6. get Rear \n");
		printf("7. Display \n");
		printf("8. Size\n");
		printf("9. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isQFull(&q))
					printf("Queue is Full\n");
				else
				{
					printf("Enter data:");
					scanf("%d",&e);
					EnQueueRear(&q, e);
				}
				break;

		
			case 2: if(isQFull(&q))
					printf("Queue is Full\n");
				else
				{
					printf("Enter data:");
					scanf("%d",&e);
					EnQueueFront(&q, e);
				}
				break;




			case 3: if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = DeQueueFront(&q);
					printf("%d\n",e);
				}
				break;


			
			case 4: if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = DeQueueRear(&q);
					printf("%d\n",e);
				}
				break;

			case 5:  if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = getFront(&q);
					printf("%d\n",e);
				}
				break;


			
			case 6:  if(isQEmpty(&q))
					printf("Queue is Empty \n");
				else
				{
					e = getRear(&q);
					printf("%d\n",e);
				}
				break;

			case 7: display(&q);
				break;

			case 8: y = Qsize(&q);
				printf("size of queue = %d\n",y);
				break;

			case 9: exit(0);


		}
	}
}



void initQueue(struct Queue *q)
{
	q->front = -1;
	q->rear = -1;
}


void EnQueueRear(struct Queue *q, int e)
{
	q->rear=(q->rear+1)%SIZE;
	q->elements[q->rear]=e;
	if(q->front==-1)
		q->front = 0;
}


void EnQueueFront(struct Queue *q, int e)
{
	q->front--;

	if(q->front<0)
		q->front = SIZE-1;

	q->elements[q->front]=e;

	if(q->rear==-1)
		q->rear = 0;
}



int DeQueueFront(struct Queue *q)
{
	int e = q->elements[q->front];
	if(q->rear == q->front)
		q->rear = q->front = -1;
	else
		q->front=(q->front+1)%SIZE;
	return e;
}


int DeQueueRear(struct Queue *q)
{
	int e = q->elements[q->rear];
	if(q->rear == q->front)
		q->rear = q->front = -1;
	else
	{
		q->rear--;
		if(q->rear<0)
			q->rear = SIZE - 1;
	}
	return e;
}

int getFront(const struct Queue *q)
{
	return q->elements[q->front];
}


int getRear(const struct Queue *q)
{
	return q->elements[q->rear];
}

int isQEmpty(const struct Queue *q)
{
	if(q->front==-1)
		return 1;
	else
		return 0;
}


int isQFull(const struct Queue *q)
{
	if((q->rear+1)%SIZE == q->front)
		return 1;
	else
		return 0;
}


int Qsize(const struct Queue *q)
{
	int s;
	if(q->front==-1)
		s=0;
	else if(q->rear>=q->front)
		s=q->rear - q->front + 1;
	else
		s=SIZE-q->front + q->rear +1;

	return s;
}

void display(const struct Queue *q)
{
	int i;
	for(i=q->front;i!=q->rear;i=(i+1)%SIZE)
		printf("%d\n",q->elements[i]);

	if(q->front!=-1)
		printf("%d\n",q->elements[i]);
}

