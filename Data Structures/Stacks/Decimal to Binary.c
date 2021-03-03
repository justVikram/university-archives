#include"intstack.h"
#include<stdio.h>
void binary(int m);

int main()
{	
	int m;
	printf("Enter the decimal number : ");
	scanf("%d",&m);
	binary(m);
	return 0;
}

void binary(int m)
{
	struct stack s;
	initStack(&s);
	while(m)
	{
		push(&s, m%2);
		m=m/2;
	}

	while(!isEmpty(&s))
		printf("%d",pop(&s));


}
