#include<stdio.h>
#include<stdlib.h>
#include"intstack.h"


void reverseStack(struct stack *s);
void sortStack(struct stack *s);
void addAtBottom(struct stack *s, int e);
void addSorted(struct stack *s, int e);

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
		printf("6. Reverse stack \n");
		printf("7. Sort stack \n");
		printf("8. Exit\n");
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
					printf("Top of stack  : %d\n",e);
				}
				break;

			case 4: display(&s);
				break;

			case 5: m= size(&s);
				printf("size of stack = %d\n",m);
	
			case 6: reverseStack(&s);
				break;

			case 7: sortStack(&s);
				break;

			case 8: exit(0);
		
		}
	}
	return 0;
}


void addAtBottom(struct stack *s, int e)
{
	int y;
	if(isEmpty(s))
		push(s,e);
	else
	{
		y = pop(s);
		addAtBottom(s,e);
		push(s, y);
	}	
}


void reverseStack(struct stack *s)
{
	int e;
	if(!isEmpty(s))
	{
		e = pop(s);
		reverseStack(s);
		addAtBottom(s, e);	
	}
}


void addSorted(struct stack *s, int e)
{
	int y;
	if(isEmpty(s))
		push(s, e);
	else if(e < peek(s))
		push(s, e);
	else
	{
		y = pop(s);
		addSorted(s, e);
		push(s, y);
	}		
}


void sortStack(struct stack *s)
{
	int e;
	if(!isEmpty(s))
	{
		e = pop(s);
		sortStack(s);
		addSorted(s, e);	
	}
}
