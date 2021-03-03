#include"intstack.h"
#include<stdio.h>

void readArray(int a[],int N)
{
	for(int i = 0;i<N;i++)
		scanf("%d",&a[i]);
}

void displayArray(int a[], int N)
{
	for(int i = 0;i<N;i++)
		printf("%d\n",a[i]);
}

void deleteconsequtive(int a[],int N)
{
	struct stack s;
	initStack(&s);
	int i;
	push(&s, a[0]);
	for(i=1;i<N;i++)
	{
		if(a[i]!=peek(&s))
			push(&s, a[i]);

		else
		{
			while(i<N && a[i]==peek(&s))
				i++;
			pop(&s);
			i--;
		}
	}

	while(!isEmpty(&s))
		printf("%d\n",pop(&s));
}


int main()
{
	int a[100];
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	readArray(a,N);
//	displayArray(a,N);

	deleteconsequtive(a,N);
	
	return 0;
}
