/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
DICTIONARY WITH BINARY SEARCH TREE
*/
#include <iostream>
#include<stdlib.h>
using namespace std;
class treenode
{
	int data;
	treenode *right,*left;
	friend class tree; 
};
class queue								//queue
{
		int front,rear;
		treenode *data[30];
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void enq(treenode *temp)				//enqueue
		{
			front++;
			data[front]=temp;
		}
		treenode *deq()						//dequeue
		{
			treenode *temp;
			rear++;
			temp=data[rear];
			return temp;
		}
		int isempq()
		{
			if(front==rear)
				return 1;
			else 
				return 0;
		}
		friend class tree;
};
class tree
{
		treenode *root;
	public:
		void create()						//creation of binary search tree
		{
			char ch;
			root=new treenode;
			cout<<"Enter the data at root: ";
			cin>>root->data;
			do
			{
				treenode *temp=root;
				int flag=0;
				treenode *curr=new treenode;
				cout<<"Enter the data: ";
				cin>>curr->data;
				while(flag==0)
				{
					if(curr->data < temp->data)	//if data is less than parent,add it to left subtree
					{
						if(temp->left==NULL)
						{
							temp->left=curr;
							flag=1;
						}	
						temp=temp->left;
					}
					else				//else add it to right subtree
					{
						if(temp->right==NULL)
						{
							temp->right=curr;
							flag=1;
						}
						temp=temp->right;
					}
				}
				cout<<"Do you want to add more(y/n): ";
				cin>>ch;
			}while(ch=='y');
		}
		void bfs()						//Breadth first traversal
		{
			treenode *temp=root;
			queue q;
			q.enq(temp);
			while(!q.isempq())
			{
				temp=q.deq();				//enqueue node to queue and print data
				cout<<temp->data<<endl;
				if(temp->left!=NULL)			//move to left side
					q.enq(temp->left);		//enqueue node
				if(temp->right!=NULL)			//move to right side and enqueue node
					q.enq(temp->right);
			}
		}
		void deleten()
		{
			int flag=0,flg=0;
			treenode *curr,*s=NULL,*temp=NULL,*parent=NULL;
			curr=new treenode;
			cout<<"Enter the element to be deleted: ";
			cin>>curr->data;
			if(curr->data == root->data)			//if data is same as root ,delete root 
			{
				curr=root;
				if(curr->right==NULL)
					root=root->left;
				else if(curr->left==NULL)
					root=root->right;
				else
				{
					temp=curr->left;		//attach left subtree to right node of root
					root=curr->right;
					s=curr->right;
					while(s->left!=NULL)
					{
						s=s->left;
					}
					s->left=temp;
				}
			}
			else						//if data not same as root,
			{
				temp=root;
				while(flag==0)
				{
					if(curr->data > temp->data)
					{
						parent=temp;
						if(temp->right==NULL)	//if data is not present,make flg as 1
						{
							flg=1;
							break;
						}
						temp=temp->right;
					}
					else if(curr->data < temp->data)
					{	
						parent=temp;
						if(temp->left==NULL)
						{
							flg=1;
							break;
						}
						temp=temp->left;
					}
					else
					{
						curr=temp;
						flag=1;
					}
				}
				if(flg==1)				//if flg=1,data not found
					cout<<endl<<"Data not found try another!!\n(NOTE:If mirrored,mirror it again)"<<endl;
				else if(curr->left==NULL && curr->right==NULL)	//if it is leaf node just delete it
				{
					if(parent->left==curr)
						parent->left=NULL;
					else
						parent->right=NULL;
				}
				else if(curr->left==NULL)			//if node has single child,attach child to parent of node
				{
					if(parent->left==curr)
						parent->left=curr->right;
					else
						parent->right=curr->right;
				}
				else if(curr->right==NULL)
				{
					if(parent->left==curr)
						parent->left=curr->left;
					else
						parent->right=curr->left;
				}
				else						//if node has 2 children,
				{
					s=curr->right;
					temp=curr->left;
					while(s->left!=NULL)
					{
						s=s->left;
					}
					s->left=temp;				//take leftmost node of right node to the position of node
					if(parent->right==curr)			//to be deleted
						parent->right=curr->right;
					else
						parent->left=curr->right;
				}
			}
			curr->right=NULL;
			curr->left=NULL;
			delete curr;
			if(flg==0)
			{
				cout<<endl<<"Tree after deletion of node:"<<endl;
				bfs();
			}
		}
		void copy_r();
		treenode *copy_r(treenode *root);
		void mirror_r();
		void mirror_r(treenode *root);
};
void tree::copy_r()								//copy with recursion
{
	tree t1;
	t1.root=copy_r(root);
	cout<<"Copied tree is:"<<endl;
	t1.bfs();
}
treenode *tree::copy_r(treenode *root)						//copy tree in preorder traversal
{
	treenode *temp=NULL;
	if(root!=NULL)
	{
		temp=new treenode;
		temp->data=root->data;
		temp->left=copy_r(root->left);
		temp->right=copy_r(root->right);
	}
	return temp;
}
void tree::mirror_r()								//mirroring with recursion
{
	mirror_r(root);
	cout<<"Mirrored tree is: "<<endl;
	bfs();
}
void tree:: mirror_r(treenode *root)						//just swap left subtree of each node with right subtree
{
	treenode *temp;
	temp=root->right;
	root->right=root->left;
	root->left=temp;
	if(root->left!=NULL)
		mirror_r(root->left);
	if(root->right!=NULL)
		mirror_r(root->right);
}


int main()
{
	tree t,t1;
	int choice;
	while(1)
	{
		cout<<"\n***********MENU***********\n1.Create\n2.Traverse.\n3.Delete node.\n4.Copy.\n5.Mirror image.\n6.Exit.\nEnter the choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	t.create();
			break;
			case 2:	t.bfs();
			break;
			case 3:	t.deleten();
			break;
			case 4:	t.copy_r();
			break;
			case 5:	t.mirror_r();
			break;
			case 6:	exit(1);
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
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 1
Enter the data at root: 12
Enter the data: 6
Do you want to add more(y/n): y
Enter the data: 8
Do you want to add more(y/n): y
Enter the data: 2
Do you want to add more(y/n): y
Enter the data: 4
Do you want to add more(y/n): y
Enter the data: 20
Do you want to add more(y/n): y
Enter the data: 18
Do you want to add more(y/n): y
Enter the data: 1
Do you want to add more(y/n): n

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 2
12
6
20
2
8
18
1
4

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 3
Enter the element to be deleted: 12
20
18
6
2
8
1
4

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 3
Enter the element to be deleted: 15

Data not found try another!!
(NOTE:If mirrored,mirror it again)

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 3
Enter the element to be deleted: 2

Tree after deletion of node:
20
18
6
4
8
1

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 4
Copied tree is:
20
18
6
4
8
1

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 5
Mirrored tree is: 
20
18
6
8
4
1

***********MENU***********
1.Create
2.Traverse.
3.Delete node.
4.Copy.
5.Mirror image.
6.Exit.
Enter the choice: 6
*/
