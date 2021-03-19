/*
		Refer String stack video and program using Arrays
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data[20];
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



void push(struct stack *s, char e[])
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Stack overflow\n");
		return ;
	}

	strcpy(p->data , e);
	p->next = s->top;
	s->top = p;
}


char * pop(struct stack *s)
{
	struct node * p = s->top;
	static char e[20];
	strcpy(e,  p->data);
	s->top = p->next;
	free(p);
	return e;
}


char* peek(const struct stack *s)
{
	struct node * p = s->top;
	static char e[20];
	strcpy(e,  p->data);
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
		printf("%s\n",p->data);
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
