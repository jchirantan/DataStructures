/*
Name:Chirantan Joshi
Division:G
Batch: G1
Roll No.:PG13
TREE OPERATIONS WITH AND WITHOUT RECURSION
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class treenode								//treenode class
{
	int data;
	treenode *right,*left;						//right and left pointers for treenode
	friend class tree; 
};
class stack							//stack
{
		int top;
		treenode *data[30];
	public:
		stack()
		{top=-1;}
		void push(treenode *temp)			//push
		{
			top++;
			data[top]=temp;
		}
		treenode *pop()					//pop
		{
			treenode *temp;
			temp=data[top];
			top--;
			return temp;
		}
		int isemp()					//check empty or not
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		friend class tree;
};
class tree
{
		treenode *root;						//creating root
	public:
		tree()
		{
			root=NULL;
		}
		void create_r()						//creating tree with recursion
		{
			root=new treenode;
			cout<<"Enter the data at root: ";
			cin>>root->data;
			create_r(root);					//passing root to create function
		}
		void create_r(treenode *temp)
		{
			treenode *curr;					//current node to traverse tree
			char choicel='n',choicer='n';
			cout<<"Do you want to add node to left of "<<temp->data<<" (y/n): ";
			cin>>choicel;
			if(choicel=='y')				//creating left subtree with recursion
			{
				curr=new treenode;
				cout<<"Enter the data: ";
				cin>>curr->data;
				temp->left=curr;
				create_r(curr);
			}
			cout<<"Do you want to add node to right of "<<temp->data<<" (y/n): ";
			cin>>choicer;
			if(choicer=='y')				//creating right subtree with recursion
			{
				curr=new treenode;
				cout<<"Enter the data: ";
				cin>>curr->data;
				temp->right=curr;
				create_r(curr);
			}			
		}
		void create_nr()				//creation whout recursion
		{
			char choice='n',choicelr='n';
			treenode *temp,*curr;
			if(root==NULL)				//first node
			{
				root=new treenode;
				cout<<"Enter the data at root: ";
				cin>>root->data;
			}		
			do
			{
				temp=root;
				int flag=0;
				while(flag==0)
				{
					cout<<"Enter at which side of "<<temp->data<<" you want to add node(l/r): ";
					cin>>choicelr;
					if(choicelr=='l')	//left subtree
					{
						if(temp->left==NULL)
						{
							curr=new treenode;
							cout<<"Enter the data at left of "<<temp->data<<": ";
							cin>>curr->data;
							temp->left=curr;
							flag=1;
						}
						temp=temp->left;
					}
					else			//right subtree
					{
						if(temp->right==NULL)
						{
							curr=new treenode;
							cout<<"Enter the data at right of "<<temp->data<<": ";
							cin>>curr->data;
							temp->right=curr;
							flag=1;
						}
						temp=temp->right;
					}
				}
				cout<<"Do you want to add more nodes(y/n)? ";
				cin>>choice;
			}while(choice=='y');			//continue till choice yes
		}
		void inorder_r()
		{
			inorder_r(root);
		}
		void preorder_r()
		{
			preorder_r(root);
		}	
		void postorder_r()
		{
			postorder_r(root);
		}
		void inorder_r(treenode *temp)				//inorder traversal
		{
			if(temp!=NULL)
			{
				inorder_r(temp->left);			//traversing left subtree
				cout<<temp->data<<endl;			//visit node
				inorder_r(temp->right);			//traversing right subtree
			}
		}
		void preorder_r(treenode *temp)				//preorder traversal
		{
			if(temp!=NULL)
			{
				cout<<temp->data<<endl;			//visit node
				preorder_r(temp->left);			//traversing left subtree
				preorder_r(temp->right);		//traversing right subtree
			}
		}
		void postorder_r(treenode *temp)			//postorder traversal
		{
			if(temp!=NULL)
			{
				postorder_r(temp->left);		//traversing left subtree
				postorder_r(temp->right);		//traversing right subtree
				cout<<temp->data<<endl;			//visit node
			}
		}
		void inorder_nr()
		{
			stack s;
			treenode *temp=root;
			while(1)				//infinite loop
			{
				while(temp!=NULL)
				{
					s.push(temp);		//push node in stack and move to left subtree
					temp=temp->left;
				}
				if(s.isemp()==1)		//if stack empty break loop
					break;
				temp=s.pop();			//visit node from stack
				cout<<temp->data<<endl;		
				temp=temp->right;		//move to right subtree
			}
		}
		void preorder_nr()					//preorder traversal
		{
			stack s;
			treenode *temp=root;
			while(1)
			{
				while(temp!=NULL)
				{
					cout<<temp->data<<endl;	//visit node
					s.push(temp);		//push node to stack and move to left subtree
					temp=temp->left;	
				}
				if(s.isemp())
					break;
				temp=s.pop();
				temp=temp->right;		//move to right subtree
			}
		}
		void postorder_nr()				//postorder traversal
		{
			stack s;
			treenode *temp=root;
			while(1)
			{
				while(temp!=NULL)
				{
					s.push(temp);		//push node to stack and move to left subtree
					temp=temp->left;
				}
				if(s.data[s.top]->right==NULL)	//move to right subtree
				{
					temp=s.pop();
					cout<<temp->data<<endl;
				}
				while(!s.isemp()&&s.data[s.top]->right==temp)	//visit node from stack
				{
					temp=s.pop();
					cout<<temp->data<<endl;
				}
				if(s.isemp())
					break;
				temp=s.data[s.top]->right;
			}
		}
};
int main()
{
	tree bt;
	int num;
	while(1)
	{
		cout<<"\n-------------MENU-------------\n1.Create with recursion.\n2.Create without recursion.\n3.Inorder with recursion.\n4.Inorder without recursion.\n5.Preorder with recursion.\n6.Preorder without recursion.\n7.Postorder with recursion.\n8.Postorder without recursion.\n9.Exit.\nEnter your choice: ";
		cin>>num;
		cout<<endl;
		switch(num)
		{
			case 1:	bt.create_r();
			break;
			case 2:	bt.create_nr();
			break;
			case 3:	cout<<"Inorder traversal without recursion: "<<endl;	
				bt.inorder_r();
			break;
			case 4:	cout<<"Inorder traversal with recursion: "<<endl;	
				bt.inorder_nr();
			break;
			case 5:	cout<<"Preorder traversal without recursion: "<<endl;	
				bt.preorder_r();
			break;
			case 6:	cout<<"Preorder traversal with recursion: "<<endl;	
				bt.preorder_nr();
			break;
			case 7:	cout<<"Postorder traversal without recursion: "<<endl;
				bt.postorder_r();
			break;
			case 8:	cout<<"Postorder traversal with recursion: "<<endl;
				bt.postorder_nr();
			break;
			case 9: exit(1);
			break;
			default:cout<<"Wrong choice!!";
		}
	}
	return 0;
}
/*
OUTPUT:

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 1

Enter the data at root: 12
Do you want to add node to left of 12 (y/n): y
Enter the data: 6
Do you want to add node to left of 6 (y/n): y
Enter the data: 2
Do you want to add node to left of 2 (y/n): n
Do you want to add node to right of 2 (y/n): n
Do you want to add node to right of 6 (y/n): y
Enter the data: 4
Do you want to add node to left of 4 (y/n): y
Enter the data: 1
Do you want to add node to left of 1 (y/n): n
Do you want to add node to right of 1 (y/n): n
Do you want to add node to right of 4 (y/n): n
Do you want to add node to right of 12 (y/n): y
Enter the data: 8
Do you want to add node to left of 8 (y/n): n
Do you want to add node to right of 8 (y/n): n

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 3

Inorder traversal without recursion: 
2
6
1
4
12
8

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 4

Inorder traversal with recursion: 
2
6
1
4
12
8

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 5

Preorder traversal without recursion: 
12
6
2
4
1
8

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 6

Preorder traversal with recursion: 
12
6
2
4
1
8

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 7

Postorder traversal without recursion: 
2
1
4
6
8
12

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 8

Postorder traversal with recursion: 
2
1
4
6
8
12

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 2

Enter at which side of 12 you want to add node(l/r): l
Enter at which side of 6 you want to add node(l/r): l 
Enter at which side of 2 you want to add node(l/r): l
Enter the data at left of 2: 5
Do you want to add more nodes(y/n)? y
Enter at which side of 12 you want to add node(l/r): r
Enter at which side of 8 you want to add node(l/r): l
Enter the data at left of 8: 10
Do you want to add more nodes(y/n)? y
Enter at which side of 12 you want to add node(l/r): r
Enter at which side of 8 you want to add node(l/r): r
Enter the data at right of 8: 20
Do you want to add more nodes(y/n)? y
Enter at which side of 12 you want to add node(l/r): r
Enter at which side of 8 you want to add node(l/r): r
Enter at which side of 20 you want to add node(l/r): l
Enter the data at left of 20: 15
Do you want to add more nodes(y/n)? n

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 3

Inorder traversal without recursion: 
5
2
6
1
4
12
10
8
15
20

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 6

Preorder traversal with recursion: 
12
6
2
5
4
1
8
10
20
15

-------------MENU-------------
1.Create with recursion.
2.Create without recursion.
3.Inorder with recursion.
4.Inorder without recursion.
5.Preorder with recursion.
6.Preorder without recursion.
7.Postorder with recursion.
8.Postorder without recursion.
9.Exit.
Enter your choice: 9


*/
