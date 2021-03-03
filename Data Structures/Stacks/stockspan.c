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


void calculateSpan(int a[], int span[],int N)
{
	struct stack s;
	initStack(&s);
	push(&s, 0);
	span[0]=1;

	int i;

	for(i=1;i<N;i++)
	{
		if(a[i]<a[peek(&s)])
		{
			push(&s, i);
			span[i] = 1;
		}
	
		else
		{
			while(!isEmpty(&s) && a[i]>=a[peek(&s)])
				pop(&s);

			if(isEmpty(&s))
				span[i]=i+1;

			else
				span[i] = i-peek(&s);

			push(&s, i);
		}
	}
}


int main()
{
	int a[100];
	int span[100];
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	readArray(a,N);

	calculateSpan(a, span, N);
	
	printf("Spans are \n");
	displayArray(span, N);
	
	return 0;
}
