#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack
{
	int elements[SIZE];
	int top1;
	int top2;
};


void initStack(struct stack *s)
{
	s->top1=-1;
	s->top2=SIZE;
}


int isFull(const struct stack *s)
{
	return (s->top1+1)==s->top2;
}


void push1(struct stack *s, int e)
{
	s->top1++;
	s->elements[s->top1]=e;
}

void push2(struct stack *s, int e)
{
	s->top2--;
	s->elements[s->top2]=e;
}

int isEmpty1(const struct stack *s)
{
	return s->top1==-1;
}

int isEmpty2(const struct stack *s)
{
	return s->top2==-1;
}

int pop1(struct stack *s)
{
	int e = s->elements[s->top1];
	s->top1--;
	return e;
}

int pop2(struct stack *s)
{
	int e = s->elements[s->top2];
	s->top2++;
	return e;
}

int peek1(const struct stack *s)
{
	return s->elements[s->top1];
}

int peek2(const struct stack *s)
{
	return s->elements[s->top2];
}

void display1(const struct stack *s)
{
	for(int i = s->top1;i>=0;i--)
		printf("%d\n",s->elements[i]);
}

void display2(const struct stack *s)
{
	for(int i = s->top2;i<SIZE;i++)
		printf("%d\n",s->elements[i]);
}


int size1(const struct stack *s)
{
	return s->top1+1;
}

int size2(const struct stack *s)
{
	return SIZE - s->top2;
}


int main()
{
	struct stack s;
	initStack(&s);
	int ch, e, m;
	while(1)
	{
		printf("1. Push on stack 1\n");
		printf("2. Push on stack 2\n");
		printf("3. Pop from stack 1\n");
		printf("4. Pop from stack 2\n");
		printf("5. Peek from stack 1\n");
		printf("6. Peek from stack 2\n");
		printf("7. Display stack 1\n");
		printf("8. Display stack 1\n");
		printf("9. Size of stack 1\n");
		printf("10. Size of stack 2\n");
		printf("11. Exit\n");
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
					push1(&s,e);
				}
				break;

			case 2: if(isFull(&s))
					printf("Stack Overflow\n");
				else
				{
					printf("Enter element :");
					scanf("%d",&e);
					push2(&s,e);
				}
				break;


			case 3: if(isEmpty1(&s))
					printf("Stack Underflow\n");
				else
				{
					e = pop1(&s);
					printf("Popped Item : %d\n",e);
				}
				break;

			case 4: if(isEmpty2(&s))
					printf("Stack Underflow\n");
				else
				{
					e = pop2(&s);
					printf("Popped Item : %d\n",e);
				}
				break;



			case 5:if(isEmpty1(&s))
					printf("Stack Underflow\n");
				else
				{
					e = peek1(&s);
					printf("Top of stack : %d\n",e);
				}
				break;

			case 6:if(isEmpty2(&s))
					printf("Stack Underflow\n");
				else
				{
					e = peek2(&s);
					printf("Top of stack : %d\n",e);
				}
				break;



			case 7: display1(&s);
				break;

			case 8: display2(&s);
				break;

			case 9: m= size1(&s);
				printf("size of stack1 = %d\n",m);
	
			
			case 10: m= size2(&s);
				printf("size of stack2 = %d\n",m);

			case 11: exit(0);
		
		}
	}
	return 0;
}

