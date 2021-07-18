/*
Name: Chirantan Joshi
Div: E
Batch: E1
Roll no.: PE11
Assignment: 5
*/
#include <stdio.h>
#include <stdlib.h>
#define max 20								//maximum limit in queue
int q[max];								//linear queue
int q1[max];								//circular queue
int front1=0,rear1=0;							//pointers for circular queue
int front=-1,rear=-1;
int is_full()								//is full function for linear queue
{
	if(rear==max-1)
		return 1;
	else
		return 0;
}
int is_emt()								//is empty function for linear queue
{
	if(front==rear)
		return 1;
	else
		return 0;
}
int is_full1()								//is full function for cicular queue
{
	if((rear1+1)%max==front1)
		return 1;
	else
		return 0;
}
int is_emt1()								//is empty function for circular queue
{
	if(rear1==front1)
		return 1;
	else
		return 0;
}
void cenq(int data)							//add element in circular queue
{
	if(!is_full1())
	{
		rear1=(rear1+1)%max;
		q1[rear1]=data;
	}
	else
		printf("No more orders allowed!!\n");
}
int cdeq()								//delete element in circular queue
{
	int data;
	if(!is_emt1())
	{
		front1=(front1+1)%max;
		data=q1[front1];
		return data;
	}
	else
		return -1;
}
void enq(int data)							//add element in linear queue
{
	if(!is_full())
	{
		rear++;
		q[rear]=data;
		printf("The order added successfully!\n");
	}
	else
	{
		printf("No more orders allowed!!\n");
		front=0;rear=-1;
	}
}
int deq()								//delete element from linear queue
{
	int data;
	if(!is_emt())
	{
		front++;
		data=q[front];
		return data;
	}
	else
	{
		front=-1;rear=-1;
		return -1;
	}
}
int main()
{
	int choice1,choice2,temp,i;
	printf("\n******* MENU *******\n");
	printf("1.By circular queue.\n2.By linear queue.\n\nEnter the choice: ");	//to select the type of queue
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 1:	while(1)							//loop for circular queue operations
			{
				printf("\n****** MENU ******\n");
				printf("1.Accept order.\n2.Serve order.\n3.Display.\n4.Exit.\n\nEnter the choice: ");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1: printf("1.Margherita Pizza.\n2.Tandoori Paneer Pizza.\n3.Marinara Pizza.\n\nEnter choice: ");
						scanf("%d",&temp);
						cenq(temp);				//adding element to circular queue
					break;
					case 2: if(cdeq()==-1)				//deleting element
							printf("No orders to serve!!\n");
						else
							printf("Order served successfully!!\n");
					break;
					case 3:	if(!is_emt1()&&rear1<front1)		//displaying contents of queue
						{
							printf("The orders are: \n");
							for(i=front1+1;i<max;i++)
							{
								printf("%d\t",q1[i]);
							}
							for(i=0;i<rear1+1;i++)
							{
								printf("%d\t",q1[i]);
							}
							printf("\n");
						}
						else if(!is_emt1()&&rear1>front1)
						{
							printf("The orders are: \n");
							for(i=front1+1;i<rear1+1;i++)
							{
								printf("%d\t",q1[i]);
							}
							printf("\n");
						}
						else
							printf("No orders are there!\n");
					break;
					case 4: exit(1);
				}
			}
		break;
		case 2:	while(1)
			{
				printf("\n****** MENU ******\n");
				printf("1.Accept order.\n2.Serve order.\n3.Display.\n4.Exit.\n\nEnter the choice: ");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1: printf("1.Margherita Pizza.\n2.Tandoori Paneer Pizza.\n3.Marinara Pizza.\n\nEnter choice: ");
						scanf("%d",&temp);
						enq(temp);				//adding element to linear queue
					break;
					case 2: if(deq()==-1)				//deleting element
							printf("No orders to serve!!\n");
						else
							printf("Order served successfully!!\n");
					break;
					case 3:	if(!is_emt())				//Displaying contents of queue 
						{
							printf("The orders are: \n");
							for(i=front+1;i<rear+1;i++)
							{
								printf("%d\t",q[i]);
							}
							printf("\n");
						}
						else
							printf("No orders are there!\n");
					break;
					case 4: exit(1);
				}
			}
		break;
	}
	return 0;
}
/*
OUTPUT: 

******* MENU *******
1.By circular queue.
2.By linear queue.

Enter the choice: 1

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 1

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 2

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 3

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 1

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
The orders are: 
1	2	3	1	

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 3

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
The orders are: 
2	3	1	3	

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
No orders are there!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
No orders to serve!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 4


******* MENU *******
1.By circular queue.
2.By linear queue.

Enter the choice: 2

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 1
The order added successfully!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 2
The order added successfully!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 3
The order added successfully!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
The orders are: 
1	2	3	

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 1
1.Margherita Pizza.
2.Tandoori Paneer Pizza.
3.Marinara Pizza.

Enter choice: 1
The order added successfully!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
The orders are: 
1	2	3	1	

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
The orders are: 
2	3	1	

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
Order served successfully!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 2
No orders to serve!!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 3
No orders are there!

****** MENU ******
1.Accept order.
2.Serve order.
3.Display.
4.Exit.

Enter the choice: 4

*/
