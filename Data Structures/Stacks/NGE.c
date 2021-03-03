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

void NGE(int a[], int N)
{
	struct stack s;
	initStack(&s);
	for(int i=0;i<N;i++)
	{
		while(!isEmpty(&s) && a[i]>peek(&s))
		{
			printf("%d ---> %d\n",pop(&s),a[i]);
		}
		push(&s, a[i]);
	}

	while(!isEmpty(&s))
		printf("%d ---> %d\n",pop(&s),-1);
}

int main()
{
	int a[100];
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	readArray(a,N);
//	displayArray(a,N);
	printf("NGE are \n");
	NGE(a,N);
	return 0;
}
