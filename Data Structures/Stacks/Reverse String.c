#include"charstack.h"
#include<stdio.h>

void reverse(char str[]);

int main()
{
	char str[100];
	printf("Enter string :");
	scanf("%s",str);
	reverse(str);
	printf("Reverse = %s\n",str);
	return 0;
}

void reverse(char str[])
{
	struct stack s;
	initStack(&s);
	int i;
	for(i=0;str[i];i++)
		push(&s, str[i]);

	i=0;

	while(!isEmpty(&s))
	{
		str[i]=pop(&s);
		i++;
	}
}
