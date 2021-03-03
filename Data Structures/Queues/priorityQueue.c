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
int getFront(const struct Queue *);
int isQEmpty(const struct Queue *);
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
			case 1:
					printf("Enter data:");
					scanf("%d",&e);
					EnQueue(&q, e);
				
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
		while(cur && e > cur->data)
		{
			prev = cur;
			cur = cur->next; 
		}

		if(prev!=NULL)
			prev->next = p;

		p->next = cur;

		if(prev == NULL)
			q->front = p;
		
		if(cur==NULL)
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


int getFront(const struct Queue *q)
{
	return q->front->data;
}


int isQEmpty(const struct Queue *q)
{
	if(q->front==NULL)
		return 1;
	else
		return 0;
}





int Qsize(const struct Queue *q)
{
	int s=0;
	struct node *p = q->front;
	while(p)
	{
		s++;
		p=p->next;
	}

	return s;
}

void display(const struct Queue *q)
{
	struct node *p = q->front;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

