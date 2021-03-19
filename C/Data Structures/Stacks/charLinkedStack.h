#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
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



void push(struct stack *s, char e)
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


char pop(struct stack *s)
{
	struct node * p = s->top;
	char e = p->data;
	s->top = p->next;
	free(p);
	return e;
}


char peek(const struct stack *s)
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
		printf("%c\n",p->data);
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
