
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
	char title[20];
	float price;
};


struct node
{
	struct Book data;
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



void push(struct stack *s, struct Book e)
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


struct Book pop(struct stack *s)
{
	struct node * p = s->top;
	struct Book e = p->data;
	s->top = p->next;
	free(p);
	return e;
}


struct Book peek(const struct stack *s)
{
	struct node * p = s->top;
	struct Book e = p->data;	
	return e;
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
		printf("Title : %s\n",p->data.title);
		printf("Price : %f\n",p->data.price);
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
