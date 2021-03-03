
#include<stdio.h>
#include<stdlib.h>
#include"bookLinkedStack.h"
int main()
{
	struct stack s;
	initStack(&s);
	int  ch, m;
	struct Book e;

	while(1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Size\n");
		printf("6.Exit\n");
		printf("Enter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter Book details :");
				printf("Enter Title :");
				scanf("%s",e.title);

				printf("Entter price :");
				scanf("%f",&e.price);

				push(&s,e);
				break;

			case 2: if(isEmpty(&s))
					printf("Stack Underflow\n");
				else
				{
					e = pop(&s);
					printf("Popped Item :\n");
					printf("Title : %s\n",e.title);
					printf("Price : %f\n",e.price);
				}
				break;

			case 3: if(isEmpty(&s))
					printf("Stack Underflow\n");
				else
				{
					e = peek(&s);
					printf("Top of stack : \n");
					printf("Title : %s\n",e.title);
					printf("Price : %f\n",e.price);
				}
				break;

			case 4:display(&s);
				break;

			case 5: m=size(&s);
				printf("size of stack = %d\n",m);
				break;

			case 6: exit(0);
		}
	}	

	return 0;
}

