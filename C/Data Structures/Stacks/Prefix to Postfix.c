/*
Algorithm for Prefix to Postfix:

 1.   Read the Prefix expression in reverse order (from right to left)

2.    If the symbol is an operand, then push it onto the Stack

3.    If the symbol is an operator, then pop two operands from the Stack
     Create a string by concatenating the two operands and the operator after them.
     string = operand1 + operand2 + operator
     And push the resultant string back to Stack

4.    Repeat the above steps until end of Prefix expression.

5.    At end top of the stack would be the answer


*/


#include"stringstack.h"
#include<stdio.h>
#include<stdlib.h>

void prefix_to_postfix(char prefix[], char postfix[]);
int isOperand(char t);


int main()
{
	char prefix[200];
	char postfix[200];

	printf("Enter prefix :");
	scanf("%s",prefix);

	prefix_to_postfix(prefix, postfix);

	printf("Postfix = %s\n",postfix);

	return 0;
}

void prefix_to_postfix(char prefix[], char postfix[])
{
	struct stack s;
	initStack(&s);
	char str[2];
	int L = strlen(prefix);
	int i;
	char opnd1[200], opnd2[200];
	char res[200];
	for(i=L-1;i>=0;i--)
	{
		if(isOperand(prefix[i]))
		{
			str[0]=prefix[i];
			str[1]='\0';
			push(&s, str);
		}

		else
		{
			//operator
			str[0]=prefix[i];
			str[1]='\0';
			

			//operand 1
			strcpy(opnd1, pop(&s));

			//operand 2
			strcpy(opnd2, pop(&s));
			
			//Make string as opnd1 + opnd2 + operator
			
			strcpy(res, opnd1);
			strcat(res, opnd2);
			strcat(res,str);

			//Push the res back to stack
			push(&s, res);

		}
	}

	//At end top of stack will be the answer
	strcpy(postfix, pop(&s));
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
