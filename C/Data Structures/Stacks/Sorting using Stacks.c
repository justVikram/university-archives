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

void sort(int a[], int N)
{
	struct stack s, temp ;
	initStack(&s);
	initStack(&temp);
	push(&s, a[0]);
	int i;
	for( i =1 ;i<N;i++)
	{
		if(a[i]<=peek(&s))
			push(&s, a[i]);
		else
		{
			while(!isEmpty(&s) && a[i]>peek(&s))
			{
				push(&temp, pop(&s));
			}
			push(&s, a[i]);
			while(!isEmpty(&temp))
				push(&s, pop(&temp));
		}
	}
		
	i=0;
	while(!isEmpty(&s))
	{
		a[i]=pop(&s);
		i++;
	}
	
}

int main()
{
	int a[100];
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	readArray(a,N);
	printf("Array before sorting \n");
	displayArray(a,N);
	
	sort(a,N);
	printf("Array after sorting \n");
	displayArray(a, N);

	return 0;
}
