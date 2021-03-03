#include"charstack.h"
#include<stdio.h>

/*
	input : [(a+b)*(c+d)] - valid
		[(a+b)*(c+d]) - invalid
		)(a)          - invalid
		(a))          - invalid
*/


int check(char []);

int main()
{
	char par[100];
	int m;
	printf("Enter par, expression :" );
	scanf("%s",par);
	m = check(par);
	if(m==1)
		printf("valid");
	else
		printf("invalid");
	return 0;
}

int check(char par[])
{
	struct stack s;
	initStack(&s);
	int i;
	for(i=0;par[i];i++)
	{
		if(par[i]=='(' || par[i]=='{' || par[i]=='[')
			push(&s, par[i]);

		else 
		{
			if(isEmpty(&s))
				return 0;

			if(par[i]==')' && pop(&s)!='(')
				return 0;

			else if(par[i]=='}' && pop(&s)!='{')
				return 0;
			
			else if(par[i]==']' && pop(&s)!='[')
				return 0;
		}
	}
	return isEmpty(&s);
}
