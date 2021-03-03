#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct stack
{
	char elements[SIZE];
	int top;
};


void initStack(struct stack *s)
{
	s->top=-1;
}


int isFull(const struct stack *s)
{
	return s->top==SIZE-1;
}


void push(struct stack *s, char e)
{
	s->top++;
	s->elements[s->top]=e;
}


int isEmpty(const struct stack *s)
{
	return s->top==-1;
}


char pop(struct stack *s)
{
	int e = s->elements[s->top];
	s->top--;
	return e;
}

char peek(const struct stack *s)
{
	return s->elements[s->top];
}

void display(const struct stack *s)
{
	for(int i = s->top;i>=0;i--)
		printf("%c\n",s->elements[i]);
}

int size(const struct stack *s)
{
	return s->top+1;
}
