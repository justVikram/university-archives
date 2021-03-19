#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct Book
{
	char title[20];
	float price;   //we have taken only two attributes, you may add as much as you want
};

struct stack
{
	struct Book elements[SIZE];
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


void push(struct stack *s, struct Book e)
{
	s->top++;
	s->elements[s->top]=e;
}


int isEmpty(const struct stack *s)
{
	return s->top==-1;
}


struct Book pop(struct stack *s)
{
	struct Book e = s->elements[s->top];
	s->top--;
	return e;
}

struct Book peek(const struct stack *s)
{
	return s->elements[s->top];
}

void display(const struct stack *s)
{
	for(int i = s->top;i>=0;i--)
	{
		printf("%s\n",s->elements[i].title);
		printf("%f\n",s->elements[i].price);
	}
}

int size(const struct stack *s)
{
	return s->top+1;
}
