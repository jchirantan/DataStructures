/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
THREADED BINARY TREE OPERATIONS
*/
#include <iostream>
#include<stdlib.h>
using namespace std;
class treenode
{
		int data;
		bool rbit,lbit;
		treenode *right,*left;
		friend class tree;
	public:
		treenode(); 
};
treenode::treenode()							//make lbit and rbit of a treenode as 1 initially
{
	lbit=1;
	rbit=1;
}
class tree								
{
		treenode *root;
		treenode *head;						//make dummy node and attach root to left of head
	public:
		tree()
		{
			head=new treenode;
			head->rbit=0;
			head->left=head;
			head->right=head;
		}
		void create()
		{
			char choice,choice1;
			root=new treenode;
			cout<<"Enter the data at root: ";
			cin>>root->data;
			head->lbit=0;
			root->left=head;
			root->right=head;
			head->left=root;
			do
			{
				int flag=0;
				treenode *curr,*temp=root;
				curr=new treenode;
				cout<<"Enter the data: ";
				cin>>curr->data;
				while(flag==0)
				{
					cout<<"At which side of "<<temp->data<<" you want to add node(l/r): ";
					cin>>choice1;
					if(choice1=='l')
					{
						if(temp->lbit==1)	//attach new node to right or left of existing node
						{
							curr->right=temp;
							curr->left=temp->left;
							temp->left=curr;//make thread from new node's left to existing node's left
							temp->lbit=0;	//if thread is made put that side bit as 1 else put 0
							flag=1;
						}
						else
							temp=temp->left;
					}
					else
					{
						if(temp->rbit==1)
						{
							curr->left=temp;
							curr->right=temp->right;
							temp->right=curr;//make thread from new node's right to existing node's right
							temp->rbit=0;
							flag=1;
						}
						else
							temp=temp->right;
					}
				}
				cout<<"Do you want to continue(y/n): ";
				cin>>choice;
			}while(choice=='y');
		}
		void inorder()						//inorder traversal
		{
			cout<<endl<<"Inorder traversal of tree is:"<<endl;
			treenode *temp=head;
			while(1)
			{
				temp=inordersucc(temp);
				if(temp==head)
					break;
				cout<<temp->data<<endl;
			}
		}
		treenode *inordersucc(treenode *temp)			//traverse tree in direction of links not threads 
		{
			treenode *x=temp->right;
			if(temp->rbit==0)
			{
				while(x->lbit==0)
				{
					x=x->left;
				}
			}
			return x;
		}
		void preorder()						//preorder traversal
		{
			cout<<endl<<"Preorder traversal of tree is:"<<endl;
			treenode *temp=head->left;
			while(temp!=head)
			{
				cout<<temp->data<<endl;			//print node
				while(temp->lbit!=1)			//traverse left links
				{
					temp=temp->left;
					cout<<temp->data<<endl;
				}
				while(temp->rbit==1)			//traverse right threads
				{
					temp=temp->right;
				}
				temp=temp->right;
			}
		}	
};
int main()
{
	tree tbt;
	int choice;
	while(1)
	{
		cout<<"\n***********MENU***********\n1.Create\n2.Inorder.\n3.Preorder.\n4.Exit.\nEnter the choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	tbt.create();
			break;
			case 2:	tbt.inorder();
			break;
			case 3:	tbt.preorder();
			break;
			case 4:	exit(1);
			break;
			default:cout<<"Enter the correct choice!!";	 
		}
	}
	return 0;
}


/*
OUTPUT:

***********MENU***********
1.Create
2.Inorder.
3.Preorder.
4.Exit.
Enter the choice: 1
Enter the data at root: 12
Enter the data: 6
At which side of 12 you want to add node(l/r): l
Do you want to continue(y/n): y
Enter the data: 8
At which side of 12 you want to add node(l/r): r
Do you want to continue(y/n): y
Enter the data: 2
At which side of 12 you want to add node(l/r): l
At which side of 6 you want to add node(l/r): l
Do you want to continue(y/n): y
Enter the data: 4
At which side of 12 you want to add node(l/r): l
At which side of 6 you want to add node(l/r): r
Do you want to continue(y/n): y
Enter the data: 1
At which side of 12 you want to add node(l/r): l
At which side of 6 you want to add node(l/r): r
At which side of 4 you want to add node(l/r): l
Do you want to continue(y/n): y
Enter the data: 18
At which side of 12 you want to add node(l/r): r
At which side of 8 you want to add node(l/r): r
Do you want to continue(y/n): n

***********MENU***********
1.Create
2.Inorder.
3.Preorder.
4.Exit.
Enter the choice: 2

Inorder traversal of tree is:
2
6
1
4
12
8
18

***********MENU***********
1.Create
2.Inorder.
3.Preorder.
4.Exit.
Enter the choice: 3

Preorder traversal of tree is:
12
6
2
4
1
8
18

***********MENU***********
1.Create
2.Inorder.
3.Preorder.
4.Exit.
Enter the choice: 4
*/
