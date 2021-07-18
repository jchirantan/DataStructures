/*
Name: Chirantan Joshi
Div: E
Batch: E1
Roll no.: PE11
Assignment: 4.header
*/
/* stack.h
 *
 *  Created on: 09-Dec-2019
 *      Author: mitwpu
 */

#ifndef STACK_H_
#define STACK_H_
#define max 50

char stack[max];						//stack for characters
int top=-1;							//pointer to stack
int is_empty()							//checking if stack is empty
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int is_full()							//checking if stack is full
{
	if(top==max)
		return 1;
	else
		return 0;
}
void push(char item)						//push item
{
	if(!is_full())
	{
		top++;
		stack[top]=item;
	}
	else
		("The stack is full!!");
}
char pop()							//pop item
{
	char data;
	if(!is_empty())
	{
		data=stack[top];
		top--;
		return data;
	}
	else
		return '$';
}

#endif /* STACK_H_ */
