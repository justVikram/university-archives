#include"charstack.h"
#include<stdio.h>
#include<math.h>
#include<string.h>

int reversal (char par[])
{

	if(strlen(par) % 2 ==1)
		return -1;

	struct stack s;
	initStack(&s);
	int i;
	int x = 0, y=0;
	for(i=0;par[i];i++)
	{
		if(par[i]=='(')
			push(&s, par[i]);
		else
		{
			if(isEmpty(&s))
				push(&s, par[i]);
			else if(peek(&s)=='(')
				pop(&s);
		}
	}

	while(!isEmpty(&s))
	{
		char ch = pop(&s);
		if(ch=='(')
			x++;
		else
			y++;
	}

	return (ceil(x/2.0)+ceil(y/2.0));
}

int main()
{
	char par[100];
	printf("Enter par. expression :");
	scanf("%s",par);
	int count = reversal(par);
	if(count == -1)
		printf("not possible");
	else 
		printf("count = %d\n",count);
	return 0;
}
