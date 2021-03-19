#include<stdio.h>
#include<stdlib.h>
#include"intstack.h"


#ifndef SIZE
	#define SIZE 5
#endif

struct Queue
{
	struct stack s1;
	struct stack s2;
};


void initQueue(struct Queue *);
void EnQueue(struct Queue *, int);
int DeQueue(struct Queue *);
int getFront(const struct Queue *);
int isQEmpty(const struct Queue *);
int isQFull(const struct Queue *);
int Qsize(const struct Queue *);
void displayQ(const struct Queue *);


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

			case 4: displayQ(&q);
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
	initStack(&(q->s1));	
	initStack(&(q->s2));
}


void EnQueue(struct Queue *q, int e)
{
	while(!isEmpty(&q->s1))
		push(&(q->s2),pop(&(q->s1)));

	push(&(q->s1), e);

	while(!isEmpty(&q->s2))
		push(&(q->s1),pop(&(q->s2)));
}


int DeQueue(struct Queue *q)
{
	int e = pop(&(q->s1));
	return e;
}


int getFront(const struct Queue *q)
{
	int e = peek(&(q->s1));
	return e;
}


int isQEmpty(const struct Queue *q)
{
	return isEmpty(&(q->s1));
}


int isQFull(const struct Queue *q)
{
	return isFull(&(q->s1));
}


int Qsize(const struct Queue *q)
{
	return size(&(q->s1));
}

void displayQ(const struct Queue *q)
{
	display(&(q->s1));
}

