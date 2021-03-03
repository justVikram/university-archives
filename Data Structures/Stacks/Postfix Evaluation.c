#include"intstack.h"
#include<stdio.h>
#include<math.h>


int eval(char postfix[]);
int isOperand(char t);

int main()
{
	char postfix[100];
	printf("Enter postfix :");
	scanf("%s",postfix);
	int e;
	e = eval(postfix);
	printf("answer = %d\n",e);
	return 0;
}

int eval(char postfix[])
{
	int opnd1, opnd2;
	int res;
	int i, m;
	struct stack s;
	initStack(&s);


	for(i=0;postfix[i];i++)
	{
		if(isOperand(postfix[i]))
		{
			//convert to integer and push io to the stack
			m = postfix[i]-48;
			push(&s, m);
		}
		else
		{
			//operator
			opnd1 = pop(&s);
			opnd2 = pop(&s);
			switch(postfix[i])
			{
				case '+' : res = opnd2+opnd1;
					   break;
				case '-' : res = opnd2-opnd1;
					   break;
				case '*' : res = opnd2*opnd1;
					   break;
				case '/' : res = opnd2/opnd1;
					   break;
				case '$' : res = pow(opnd2,opnd1);
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
