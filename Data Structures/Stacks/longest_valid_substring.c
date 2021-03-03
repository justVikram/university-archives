#include<stdio.h>

int max(char par[])
{
	int c = 0;
	int max = 0;
	int i;
	for(i=0;par[i];i++)
	{
		if(par[i]=='(')
		{
			c++;
			if(max<c)
				max = c;
		}
		else if(par[i]==')')
			c--;
	}
	return max;
}

int main()
{
	char par[100];
	printf("Enter par. expression :");
	scanf("%s",par);
	int count = max(par);
	printf("count = %d\n",count);
	return 0;
}
