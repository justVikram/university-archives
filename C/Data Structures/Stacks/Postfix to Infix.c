/*  Algorithm for Postfix to Infix:

    1. Read the Postfix expression from left to right

    2. If the symbol is an operand, then push it onto the Stack

    3. If the symbol is an operator, then pop two operands from the Stack
       Create a string by concatenating the two operands and the operator between them.
       string = (operand2 + operator + operand1),  And push the resultant string back to Stack
    4. Repeat the above steps until end of Postfix expression.

    5. At end top of stack would be the answer
*/

#include"stringstack.h"
#include<stdio.h>
#include<stdlib.h>

void postfix_to_infix(char postfix[], char infix[]);
int isOperand(char t);


int main()
{
	char postfix[200];
	char infix[200];

	printf("Enter postfix :");
	scanf("%s",postfix);

	postfix_to_infix(postfix, infix);

	printf("infix = %s\n",infix);

	return 0;
}

void postfix_to_infix(char postfix[], char infix[])
{
	struct stack s;
	initStack(&s);
	char str[2];

	int i;
	char opnd1[200], opnd2[200];
	char res[200];

	for(i=0;postfix[i];i++)
	{
		if(isOperand(postfix[i]))
		{
			str[0]=postfix[i];
			str[1]='\0';
			push(&s, str);
		}

		else
		{
			//operator
			str[0]=postfix[i];
			str[1]='\0';
			

			//operand 1
			strcpy(opnd1, pop(&s));

			//operand 2
			strcpy(opnd2, pop(&s));
			
			//Make string as (opnd2 + operator + opnd1)
			
			strcpy(res, "(");
			strcat(res, opnd2);
			strcat(res, str);
			strcat(res, opnd1);
			strcat(res, ")");

			//Push the res back to stack
			push(&s, res);

		}
	}

	//At end top of stack will be the answer
	strcpy(infix, pop(&s));
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
