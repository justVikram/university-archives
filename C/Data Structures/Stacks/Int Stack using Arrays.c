#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
	int elements[SIZE];
	int top;
};

void initStack(struct stack *s);
int isFull(const struct stack *s);
void push(struct stack *s, int e);
int isEmpty(const struct stack *s);
int pop(struct stack *s);
int peek(const struct stack *s);
void display(const struct stack *s);
int size(const struct stack *s);


int main()
{
	struct stack s;
	initStack(&s);
	int ch, e, m;
	while(1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Size\n");
		printf("6. Exit\n");
		printf("Enter Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isFull(&s))
					printf("Stack Overflow\n");
				else
				{
					printf("Enter element :");
					scanf("%d",&e);
					push(&s,e);
				}
				break;

			case 2: if(isEmpty(&s))
					printf("Stack Underflow\n");
				else
				{
					e = pop(&s);
					printf("Popped Item : %d\n",e);
				}
				break;

			case 3:if(isEmpty(&s))
					printf("Stack Underflow\n");
				else
				{
					e = peek(&s);
					printf("Popped Item : %d\n",e);
				}
				break;

			case 4: display(&s);
				break;

			case 5: m= size(&s);
				printf("size of stack = %d\n",m);
	
			case 6: exit(0);
		
		}
	}
	return 0;
}

void initStack(struct stack *s)
{
	s->top=-1;
}


int isFull(const struct stack *s)
{
	return s->top==SIZE-1;
}


void push(struct stack *s, int e)
{
	s->top++;
	s->elements[s->top]=e;
}


int isEmpty(const struct stack *s)
{
	return s->top==-1;
}


int pop(struct stack *s)
{
	int e = s->elements[s->top];
	s->top--;
	return e;
}

int peek(const struct stack *s)
{
	return s->elements[s->top];
}

void display(const struct stack *s)
{
	for(int i = s->top;i>=0;i--)
		printf("%d\n",s->elements[i]);
}

int size(const struct stack *s)
{
	return s->top+1;
}
