#include <stdio.h>  
#include <stdlib.h>
typedef struct node							//structure for node
{
	int data;							//data field
	struct node *next;						//next field(link)
}nodes;
nodes *getnode()							//function to create one node
{
	int i;
	nodes *temp;
	temp=(nodes*)malloc(sizeof(nodes));				//Allocating memory to node
	printf("Enter the data: ");
	scanf("%d",&i);
	temp -> data=i;
	temp -> next=NULL;
	return temp;
}
void create(nodes *head)						//Function to link all created nodes
{
	int i;
	char ch='n';
	nodes *temp,*last=NULL;
	temp=(nodes*)malloc(sizeof(nodes));				//Allocating memory to node
	printf("Do you want to create new node?(y/n): ");
	scanf(" %c",&ch);	
	while(ch=='y')	
	{
		temp=getnode();
		if(last==NULL)
		{
			last=temp;
			head -> next=last;				//Linking head node with first node
		}
		else
		{
			last->next=temp;				//Linking all other created nodes
			last=temp;
		}
		printf("Do you want to create new node?(y/n): ");
		scanf(" %c",&ch);
	}
}
void display(nodes *head)						//Function to display all data in list
{
	nodes *curr;
	curr=head->next;
	printf("The contents of linked list are:\n");
	if(head -> next==NULL)						//if head->next is NULL list is empty
		printf("The list is empty!!\n");
	else if(curr==NULL)
	{
		printf("%d\t",curr -> data);				//else print data by links
		curr=curr -> next;
	}
	else
	{
		while(curr!=NULL)
		{
			printf("%d\t",curr -> data);
			curr=curr -> next;
		}
	}
	printf("\n");
}
int length(nodes *head)							//Function to find length of list
{
	nodes *curr;
	curr=head->next;
	int cnt=0;
	if(head->next==NULL)
		return 0;
	else
	{
		while(curr!=NULL)					//incrementing count till current->next is NULL
		{
			cnt++;
			curr=curr->next;
		}
		return cnt;
	}
}
void insert(nodes *head)						//Function to insert node at any position in list
{
	nodes *curr=head,*nnode;
	int i=1,k=length(curr),pos;
	printf("Enter the position to which a node to be inserted: ");
	scanf("%d",&pos);
	nnode=getnode();
	if(pos>k+1)							//position is greater than length+1, node can't be inserted
		printf("Data can't be inserted!!\n");
	else
	{
		while(curr!=NULL&&i<pos)				//else take current pointer to position
		{
			curr=curr->next;
			i++;
		}
		nnode->next=curr->next;					//insert node at that position
		curr->next=nnode;					//Adjusting links
		printf("Node inserted successfully!!\n");
	}
	display(head);
}
void delete(nodes *head)						//Function to delete node from any position
{
	nodes *prev=head;
	int i=0,k=length(prev),pos;
	printf("Enter the position from which a node to be deleted: ");
	scanf("%d",&pos);
	if(pos>k)							//If position is greater than length, node can't be deleted
		printf("Node can't be deleted!!\n");
	else								
	{
		while(prev!=NULL&&i<pos-1)		
		{
			prev=prev->next;				//else take previous pointer to position
			i++;
		}
		nodes *temp=prev->next;
		prev->next=temp->next;					//adjusting links
		free(temp);						//freeing memory allocated for node
		printf("The node deleted successfully!!\n");
	}
	display(head);
}
void reverse(nodes *head)						//Function to reverse the linked list
{
	nodes *ptr=NULL,*mid=NULL,*prev=NULL;
	ptr=head->next;
	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->next;						//reversing the list by adjusting links
		mid->next=prev;
	}
	head->next=mid;							//Linking head with first element of reversed list
	printf("The list is reversed successfully!!\n");
	display(head);
}
void sort(nodes *head)							//Function to sort the data
{
	nodes *p,*q;
	int data;
	q=head->next;
	while(q!=NULL)
	{
		p=q->next;
		while(p!=NULL)
		{
			if(q->data > p->data)				//Using selection sort to swap data items and links.
			{
				data=p->data;				
				p->data=q->data;
				q->data=data;
			}
			p=p->next;
		}
		q=q->next;
	}
	printf("The list is sorted successfully!!\n");
	display(head);
}
void merge(nodes *head1,nodes *head2,nodes *head3)					//Function to Merge 2 lists
{
	nodes *curr1=head1->next,*curr2=head2->next,*last=NULL;
	while(curr1!=NULL&&curr2!=NULL)						
	{
		if(last==NULL)
		{
			if(curr1->data > curr2->data)					//Comparing data
			{
				last=curr2;				
				head3->next=last;					//Attaching last node to head
				curr2=curr2->next;
			}
			else 
			{
				last=curr1;				
				head3->next=last;
				curr1=curr1->next;
			}
		}
		else
		{
			if(curr1->data > curr2->data)					//sorting and merging
			{
				last->next=curr2;
				last=curr2;
				curr2=curr2->next;
			}
			else 
			{
				last->next=curr1;
				last=curr1;
				curr1=curr1->next;
			}
		}
	}
	if(curr1!=NULL)								//Attaching remaining list
	{
		last->next=curr1;
	}
	if(curr2!=NULL)
	{
		last->next=curr2;
	}						
	printf("Lists merged sucessfully!!\n");
	display(head3);
}
int main()
{
	int i,choice;
	nodes *head=(nodes*)malloc(sizeof(nodes));			//creating 3 head nodes and linking them to null
	head -> next=NULL;
	nodes *head1=(nodes*)malloc(sizeof(nodes));
	head1 -> next=NULL;
	nodes *head2=(nodes*)malloc(sizeof(nodes));
	head2 -> next=NULL;
	printf("Create the list.\n\n");
	create(head);
	while(1)
	{
		printf("\n****** MENU ******\n");
		printf("1.Display list.\n2.Length of list.\n3.Insert node.\n4.Delete node.\n5.Reverse the list.\n6.Sort the list.\n7.Merge 2 lists.\n8.Exit.\n\nEnter the choice: ");				//Different choices for different operations
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	display(head);
			break;
			case 2:	i=length(head);
				printf("Length of linked list is: %d\n",i);
			break;
			case 3:	insert(head);
			break;
			case 4:	delete(head);
			break;
			case 5:	reverse(head);
			break;
			case 6:	sort(head);
			break;
			case 7:	printf("Create the second list.\n\n");
				create(head1);
				merge(head,head1,head2);
			break;
			case 8: exit(1);
			break;
			default:printf("Wrong Choice!!\nPlease enter correct choice.\n");
		}
	}
	return 0;
}
/*
OUTPUT:
Create the list.

Do you want to create new node?(y/n): y
Enter the data: 10
Do you want to create new node?(y/n): y
Enter the data: 20
Do you want to create new node?(y/n): y
Enter the data: 30
Do you want to create new node?(y/n): n

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 1
The contents of linked list are:
10	20	30	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 2
Length of linked list is: 3

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 3
Enter the position to which a node to be inserted: 2
Enter the data: 15
Node inserted successfully!!
The contents of linked list are:
10	15	20	30	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 4
Enter the position from which a node to be deleted: 2
The node deleted successfully!!
The contents of linked list are:
10	20	30	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 5
The list is reversed successfully!!
The contents of linked list are:
30	20	10	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 6
The list is sorted successfully!!
The contents of linked list are:
10	20	30	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 7
Create the second list.

Do you want to create new node?(y/n): y
Enter the data: 21
Do you want to create new node?(y/n): y
Enter the data: 34
Do you want to create new node?(y/n): n
Lists merged sucessfully!!
The contents of linked list are:
10	20	21	30	34	

****** MENU ******
1.Display list.
2.Length of list.
3.Insert node.
4.Delete node.
5.Reverse the list.
6.Sort the list.
7.Merge 2 lists.
8.Exit.

Enter the choice: 8
*/	
