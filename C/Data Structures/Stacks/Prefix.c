#include"charstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void convertPrefix(char infix[], char prefix[]);
int isOperand(char t);
int isOperator(char t);
int pre(char t);
void stringReverse(char []);


int main()
{
	char infix[20];
	char prefix[20];

	printf("Enter infix : ");
	scanf("%s",infix);

	convertPrefix(infix, prefix);

	printf("Prefix = %s\n",prefix);

	return 0;
}

void convertPrefix(char infix[], char prefix[])
{
	struct stack s;
	initStack(&s);
	int i, j=0;
	int L = strlen(infix);

	for(i=L-1;i>=0;i--)
	{
		/*
			1. If scanned character is operand, write to output string
		*/
		if(isOperand(infix[i]))
		{
			prefix[j]=infix[i];
			j++;
		}

		/*
			If the scanned character is operator
		*/

		else if(isOperator(infix[i]))
		{

			/*
				2.2.1 If stack is Empty, push the operator
				2.2.2 If the pre(scanned character) >= pre(top_stack), push
				2.2.3 If the pre(scanned character) < pre(top_stack), pop all characters from stack and write to output string, atlast push the scanned character
			*/

			while(!isEmpty(&s) && pre(infix[i])<pre(peek(&s)))
			{
				prefix[j]=pop(&s);
				j++;
			}
			push(&s, infix[i]);
		}

		/*
			3. If scanned character is ')', push the scanned charater
		*/

		else if(infix[i]==')')
			push(&s, infix[i]);

		/*
			4. If scanned character is '(', pop all operators from stack till we 				get ')', atlast pop the ')'
		*/


		else if(infix[i]=='(')
		{
			while(!isEmpty(&s) && peek(&s)!=')')
			{
				prefix[j]=pop(&s);
				j++;
			}
			pop(&s);
		}
	}//end for

	/*
		The remaining operators from stack has to be writtern to the output string
	*/


	while(!isEmpty(&s))
	{
		prefix[j]=pop(&s);
		j++;
	}

	//Add NULL character at end, to make array of characters, the string

	prefix[j]='\0';

	//Reverse prefix

	stringReverse(prefix);
}


int isOperand(char t)
{
	if(t>='A' && t<='Z')
		return 1;

	if(t>='a' && t<='z')
		return 1;

	if(t>='0' && t<='9')
		return 1;
	else
		return 0;
}

int isOperator(char t)
{
	switch(t)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '$': return 1;
	}
	return 0;
}

int pre(char t)
{
	if(t=='+' || t=='-')
		return 1;

	else if(t=='*' || t=='/')
		return 2;

	else if(t=='$')
		return 3;

	else
		return -1;
}

void stringReverse(char prefix[])
{
	int L = strlen(prefix);
	int i =0;
	int j = L-1;
	char temp;
	while(i<j)
	{
		temp = prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=temp;
		i++;
		j--;
	}
}
