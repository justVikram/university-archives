#include"intstack.h"
#include<stdio.h>
#include<math.h>
#include<string.h>

int eval(char prefix[]);
int isOperand(char t);

int main()
{
	char prefix[100];
	printf("Enter prefix :");
	scanf("%s",prefix);
	int e;
	e = eval(prefix);
	printf("answer = %d\n",e);
	return 0;
}

int eval(char prefix[])
{
	int opnd1, opnd2;
	int res;
	int i, m;
	struct stack s;
	initStack(&s);
	int L = strlen(prefix);

	for(i=L-1;i>=0;i--)
	{
		if(isOperand(prefix[i]))
		{
			//convert to integer and push io to the stack
			m = prefix[i]-48;
			push(&s, m);
		}
		else
		{
			//operator
			opnd1 = pop(&s);
			opnd2 = pop(&s);
			switch(prefix[i])
			{
				case '+' : res = opnd1+opnd2;
					   break;
				case '-' : res = opnd1-opnd2;
					   break;
				case '*' : res = opnd1*opnd2;
					   break;
				case '/' : res = opnd1/opnd2;
					   break;
				case '$' : res = pow(opnd1,opnd2);
					   break;
			}
			//push res back to the stack
			push(&s, res);
			
		}
	}

	//at end top of stack is the answer
	return pop(&s);
}

int isOperand(char t)
{
	if(t>='a' && t<='z')
		return 1;
	else if(t>='A' && t<='Z')
		return 1;
	else if(t>='0' && t<='9')
		return 1;
	else
		return 0;
}
