#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct stack
{
	struct node *top;
};


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


int peek(const struct stack *s)
{
	return s->top->data;
}


int isEmpty(const struct stack *s)
{
	return s->top==NULL;
}


void display(const struct stack *s)
{
	struct node *p=s->top;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}


int size(const struct stack *s)
{
	struct node *p=s->top;
	int c = 0;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}
