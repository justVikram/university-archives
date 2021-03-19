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

struct stack
{
	struct node *top;
};



void initQueue(struct Queue *);
void EnQueue(struct Queue *, int);
int DeQueue(struct Queue *);
int getFront(const struct Queue *);
int isQEmpty(const struct Queue *);
int Qsize(const struct Queue *);
void displayQ(const struct Queue *);
void reverseK(struct Queue *, int);
void initStack(struct stack *s);
void push(struct stack *s, int e);
int pop(struct stack *s);
int isEmpty(const struct stack *s);




int main()
{
	struct Queue q;
	initQueue(&q);
	int ch, e, y, K;
	while(1)
	{
		printf("1. EnQueue \n");
		printf("2. DeQueue \n");
		printf("3. get Front \n");
		printf("4. Display \n");
		printf("5. Size\n");
		printf("6. Reverse K \n");
		printf("7. Exit\n");
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

			case 4: displayQ(&q);
				break;

			case 5: y = Qsize(&q);
				printf("size of queue = %d\n",y);
				break;

			case 6: printf("Enter K:");
				scanf("%d",&K);
				reverseK(&q, K);
				break;

			case 7: exit(0);


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

void displayQ(const struct Queue *q)
{
	struct node *p = q->front;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

void reverseK(struct Queue *q, int K)
{
	struct stack s;
	initStack(&s);
	int i;
	int L = Qsize(q);
	for(i=1;i<=K;i++)
		push(&s, DeQueue(q));

	while(!isEmpty(&s))
		EnQueue(q, pop(&s));

	for(i=1;i<=L-K;i++)
		EnQueue(q, DeQueue(q));

	displayQ(q);
}


void initStack(struct stack *s)
{
	s->top=NULL;
}



void push(struct stack *s, int e)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Stack overflow\n");
		return ;
	}

	p->data = e;
	p->next = s->top;
	s->top = p;
}


int pop(struct stack *s)
{
	struct node * p = s->top;
	int e = p->data;
	s->top = p->next;
	free(p);
	return e;
}





int isEmpty(const struct stack *s)
{
	return s->top==NULL;
}
