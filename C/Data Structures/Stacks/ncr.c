#include<sdtio.h>
#include"fact.h"

int main()
{
	int n, r;
	scanf("%d%d",&n,&r);
	int x = fact(n)/(fact(r)*fact(n-r));
	printf("%d\n",x);
	return 0;
}
