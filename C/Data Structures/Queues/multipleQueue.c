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
	struct Queue q[3];
	for(int i = 0;i<3;i++)
		initQueue(&q[i]);
	int ch, e, y, n;
	while(1)
	{
		printf("1. EnQueue \n");
		printf("2. DeQueue \n");
		printf("3. get Front \n");
		printf("4. Display \n");
		printf("5. Size\n");
		printf("6. Exit\n");
		scanf("%d",&ch);
		if(ch!=6)
		{
			printf("Enter Queue Number :");
			scanf("%d",&n);
		}
		switch(ch)
		{
			case 1: if(isQFull(&q[n]))
					printf("Queue is Full\n");
				else
				{
					printf("Enter data:");
					scanf("%d",&e);
					EnQueue(&q[n], e);
				}
				break;


			case 2: if(isQEmpty(&q[n]))
					printf("Queue is Empty \n");
				else
				{
					e = DeQueue(&q[n]);
					printf("%d\n",e);
				}
				break;


			case 3:  if(isQEmpty(&q[n]))
					printf("Queue is Empty \n");
				else
				{
					e = getFront(&q[n]);
					printf("%d\n",e);
				}
				break;

			case 4: display(&q[n]);
				break;

			case 5: y = Qsize(&q[n]);
				printf("size of queue = %d\n",y);
				break;

			case 6: exit(0);


		}
	}
}



void initQueue(struct Queue *q)
{
	q->front = -1;
	q->rear = -1;
}


void EnQueue(struct Queue *q, int e)
{
	q->rear=(q->rear+1)%SIZE;
	q->elements[q->rear]=e;
	if(q->front==-1)
		q->front = 0;
}


int DeQueue(struct Queue *q)
{
	int e = q->elements[q->front];
	if(q->rear == q->front)
		q->rear = q->front = -1;
	else
		q->front=(q->front+1)%SIZE;
	return e;
}


int getFront(const struct Queue *q)
{
	return q->elements[q->front];
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

