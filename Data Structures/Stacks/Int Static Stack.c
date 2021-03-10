#include<stdio.h>
#include<stdlib.h>
#include"intstack.h"

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
