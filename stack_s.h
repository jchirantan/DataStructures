#ifndef STACK_H_
#define STACK_H_
#include <string.h>
#define max 50

char stack1[max][max];
int top1=-1;
int is_empty1()
{
	if(top1==-1)
		return 1;
	else
		return 0;
}
int is_full1()
{
	if(top1==max)
		return 1;
	else
		return 0;
}
void push1(char item[20])
{
	if(!is_full1())
	{
		top1++;
		strcpy(stack1[top1],item);
	}
	else
		("The stack is full!!");
}
char *pop1()
{
	if(!is_empty1())
	{
		char *data=stack1[top1];
		top1--;
		return (data);
	}
	else
		return "@";
}

#endif /* STACK_H_ */
