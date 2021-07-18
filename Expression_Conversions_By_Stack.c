/*
Name: Chirantan Joshi
Div: E
Batch: E1
Roll no.: PE11
Assignment: 4
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"								//header file for stack of character
#include <string.h>

#define max 50									//header file for string stack

char stack1[max][max];								//2-D array of character to store strings
int top1=-1;									//pointer stack						
int is_empty1()									//Check if stack is empty
{
	if(top1==-1)
		return 1;
	else
		return 0;
}
int is_full1()									//Check if stack is full
{
	if(top1==max)
		return 1;
	else
		return 0;
}
void push1(char item[20])							//push string to stack
{
	if(!is_full1())
	{
		top1++;
		strcpy(stack1[top1],item);
	}
	else
		("The stack is full!!");
}
char *pop1()									//pop string from stack using pointer
{
	if(!is_empty1())
	{
		char *data=stack1[top1];
		top1--;
		return (data);
	}
	else
		return "$";
}

void reverse(char str[20],char str1[20])					//Function to reverse the inputted string
{
	int i,n;
	n=strlen(str);								//Calculating the string length
	for(i=0;i<n;i++)
	{
		str1[i]=str[n-i-1];						//Copying letter from end.
	}
	str1[n]='\0';
}
int icp1(char ch)								//Incoming priority values for postfix conversion
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='^')
		return 4;
	else if(ch=='(')
		return 5;
	else
		return 0;
}
int isp1(char ch)								//In Stack Priorities for postfix conversion
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else
		return 0;
}
int icp2(char ch)								//Incoming priority values for prefix conversion
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else if(ch=='(')
		return 5;
	else
		return 0;
}
int isp2(char ch)								//In Stack Priorities for prefix conversion
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='^')
		return 4;
	else
		return 0;
}
void in_post(char inexp[20],char postexp[20])					//Function for converting infix to postfix
{
	char tkn;								
	int k=0,i=0;
	tkn=inexp[i];
	while(tkn!='\0')							//Checking if the expression is over or not
	{
		//if((tkn>='A' && tkn<='Z')||(tkn>='a' && tkn<='z'))		//If operand ,no stack is used
		if(isalnum(tkn))
		{
			postexp[k]=inexp[i];
			k++;
		}
		else								//Checking for operators
		{
			if(tkn=='(')						//if '(' pushing to stack		
				push('(');
			else
			{
				if(tkn==')')					//if ')' popping all operators
				{
					while((tkn=pop())!='(')
					{
						postexp[k]=tkn;
						k++;	
					}
				}
				else						//pushing or popping elements.		
				{
					while(is_empty()==0 && isp1(stack[top])>=icp1(tkn))
					{
						postexp[k]=pop();		//Checking for isp and icp
						k++;
					}
					push(tkn);
				}
			}
		}
		i++;	
		tkn=inexp[i];							//taking next character from string
	}
	while(!is_empty())							//taking all remaining operators in postfix expression
	{
		postexp[k]=pop();
		k++;
	}
	postexp[k]='\0';
}
void in_pre(char inexp[20],char pre1exp[20])					//Function for converting infix to prefix
{
	int c=0;
	while(inexp[c]!='\0')
		c++;
	char tkn,preexp[20];
	int k=0;
	tkn=inexp[c];								//reading infix expression in reverse order
	while(c>=0)								//Checking if the expression is over or not
	{
		//if((tkn>='A' && tkn<='Z')||(tkn>='a' && tkn<='z'))		//If operand ,no stack is used
		if(isalnum(tkn))
		{
			preexp[k]=inexp[c];
			k++;
		}
		else								//Checking for operators
		{
			if(tkn==')')						//if ')' pushing to stack
				push(')');
			else
			{
				if(tkn=='(')					//if '(' popping all operators
				{
					while((tkn=pop())!=')')
					{
						preexp[k]=tkn;
						k++;
					}
				}
				else						//pushing or popping elements.
				{
					while(is_empty()==0 && isp2(stack[top])>icp2(tkn))
					{
						preexp[k]=pop();		//Checking for isp and icp
							k++;
					}
					push(tkn);
				}
			}
		}
		c--;
		tkn=inexp[c];							//taking next character from string
	}
	while(!is_empty())							//taking all remaining operators in postfix expression
	{
		preexp[k]=pop();
		k++;
	}
	preexp[k]='\0';
	reverse(preexp,pre1exp);						//reversing converted expression to get prefix
}
void post_in(char inexp[30],char infix[20])					//Function for converting postfix to infix
{
	char tkn[20],op1[20],op2[20],e[20];
	int i,l,p;
	p=strlen(inexp);
	for(i=0;i<p;i++)
	{
		tkn[0]=inexp[i];
		if(tkn[0] == '+' || tkn[0] == '-' || tkn[0] == '*' || tkn[0] == '/')	 //checking is tkn is operator
		{
			strcpy(op2,pop1());					//if operator,pop 2 items from stack
			strcpy(op1,pop1());
			e[0]='(';
			e[1]='\0';
			strcat(e,op1);
			l=strlen(e);
			e[l]=tkn[0];						//create string by putting operator in between 2 operands
			e[l+1]='\0';
			strcat(e,op2);
			l=strlen(e);
			e[l]=')';
			e[l+1]='\0';
			push1(e);						//push created string to stack
		}
		else
		{
			tkn[1]='\0';			
			push1(tkn);						//push operand directly to stack
		}
	}
	strcpy(infix,pop1());							//pop the output expression from stack
}
void pre_in(char inexp[20],char infix[20])
{
	char tkn[20],op1[20],op2[20],e[20];
	int c=0,i,l,p;
	while(inexp[c]!='\0')
		c++;
	c--;
	p=strlen(inexp);
	for(i=c;i>-1;i--)							//reading string in reverse order
	{
		tkn[0]=inexp[i];
		if(tkn[0] == '+' || tkn[0] == '-' || tkn[0] == '*' || tkn[0] == '/')	 //checking is tkn is operator
		{
			strcpy(op1,pop1());
			strcpy(op2,pop1());					//if operator,pop 2 items from stack
			e[0]='(';
			e[1]='\0';
			strcat(e,op1);
			l=strlen(e);
			e[l]=tkn[0];						//create string by putting operator in between 2 operands
			e[l+1]='\0';
			strcat(e,op2);
			l=strlen(e);
			e[l]=')';
			e[l+1]='\0';
			push1(e);						//push created string to stack
		}
		else
		{
			tkn[1]='\0';
			push1(tkn);						//push operand directly to stack
		}
	}
	strcpy(infix,pop1());							//pop the output expression from stack
}
int main()
{
	int i,choice;
	char item[20],inexp[20],postexp[20],preexp[20],infix[20];
	while(1)
	{
		printf("\n----------MENU----------\n");
		printf("1.Push.\n2.Pop.\n3.Display stack.\n4.Infix to Postfix.\n5.Infix to prefix.\n6.Postfix to infix.\n7.Prefix to infix.\n8.Exit.\n\nEnter the choice: ");
		scanf("%d",&choice);						//Different choices for operations.
		switch(choice)
		{

			case 1:	printf("Enter the element to be added: ");
				scanf("%s",item);
				push1(item);
			break;
			case 2: if(pop1()!="$")
				{
					printf("Element popped successfully!\n");
				}
				else
					printf("The stack is empty!!\n");
			break;
			case 3:	if(top1>-1)
				{
					for(i=top1;i>-1;i--)
					{
						printf("%s\n",stack1[i]);
					}
				}
				else
					printf("The stack is empty.\n");
			break;
			case 4: printf("Enter the infix expression to be converted: ");
				scanf("%s",inexp);
				in_post(inexp,postexp);
				printf("The postfix expression is: %s",postexp);
			break;
			case 5:	printf("Enter the infix expression to be converted: ");
				scanf("%s",inexp);
				in_pre(inexp,preexp);
				printf("The prefix expression is: %s\n",preexp);
			break;
			case 6: printf("Enter the postfix expression to be converted: ");
				scanf("%s",inexp);
				post_in(inexp,infix);
				printf("Infix expression is: %s\n",infix);
			break;
			case 7: printf("Enter the prefix expression to be converted: ");
				scanf("%s",inexp);
				pre_in(inexp,infix);
				printf("Infix expression is: %s\n",infix);
			break;
			case 8:	exit(1);
		}
	}

	return 0;
}

/* 
OUTPUT:

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 1
Enter the element to be added: a+b

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 3
a+b

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 2
Element popped successfully!

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 3
The stack is empty.

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 4
Enter the infix expression to be converted: (a+b-c)*d-(e+f)
The postfix expression is: ab+c-d*ef+-
----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 5
Enter the infix expression to be converted: (a+b)*(b-c)
The prefix expression is: *+ab-bc

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 6
Enter the postfix expression to be converted: ab+c-d*ef+-
Infix expression is: ((((a+b)-c)*d)-(e+f))

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 7
Enter the prefix expression to be converted: *+ab-bc
Infix expression is: ((a+b)*(b-c))

----------MENU----------
1.Push.
2.Pop.
3.Display stack.
4.Infix to Postfix.
5.Infix to prefix.
6.Postfix to infix.
7.Prefix to infix.
8.Exit.

Enter the choice: 8
*/
