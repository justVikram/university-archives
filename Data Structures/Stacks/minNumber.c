#include"intstack.h"
#include<stdio.h>
#include<string.h>

void minNumber(char sequence[])
{
	struct stack s;
	initStack(&s);
	int i;
	int len = strlen(sequence);
	for(i=0;i<=len;i++)
	{
		push(&s, i+1);
		if(i==len || sequence[i]=='I')
		{
			while(!isEmpty(&s))
				printf("%d",pop(&s));
		}
	}
}


int main()
{
	char sequence[11];
	printf("Enter the sequence :");
	scanf("%s",sequence);
	minNumber(sequence);
	return 0;
}
