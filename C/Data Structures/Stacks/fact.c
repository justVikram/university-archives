#include<stdio.h>
#include"fact.h"

int main()
{	
	int n;
	scanf("%d",&n);
	int f = fact(n);
	printf("%d\n",f);
	return 0;
}
