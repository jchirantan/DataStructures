/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
GRAPH TRAVERSALS WITH AND WITHOUT RECURSION
*/
#include<iostream>
using namespace std;
class gnode
{
	int vertex;
	gnode *next;
	friend class graph;
	friend class stack;
};
class queue								//queue 
{
		int front,rear;
		gnode *data[30];
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void enq(gnode *temp)					//enqueue
		{
			front++;
			data[front]=temp;
		}
		gnode *deq()						//dequeue
		{
			gnode *temp;
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
class stack								//stack
{
		int top;
		gnode *data[30];
	public:
		stack()
		{top=-1;}
		void push(gnode *temp)					//push
		{
			top++;
			data[top]=temp;
		}
		gnode *pop()						//pop
		{
			gnode *temp;
			temp=data[top];
			top--;
			return temp;
		}
		int isemp()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		friend class graph;
};
class graph								//graph
{
		gnode *head[20];
		int n,i,visited[20][2];
	public:	
		void create()						//create
		{
			char choice,choice1;
			int v;
			gnode *curr;
			n=0,i=0;
			do				//allocate memory for heads of all nodes
			{
				head[i]=new gnode;
				cout<<"Enter the node value: ";
				cin>>head[i]->vertex;
				visited[i][0]=head[i]->vertex;		//create visited array for checking if node is visited or not
				cout<<"Do you want to add more node(y/n): ";
				cin>>choice1;
				n+=1;
				i+=1;
			}while(choice1=='y');
			for(i=0;i<n;i++)				//create linked list for each node
			{
				gnode *temp=head[i];
				cout<<endl<<"Do you want to add node adjacent to "<<head[i]->vertex<<" (y/n): ";
				cin>>choice;
				while(choice=='y')			//linked list will contain all adjacent nodes
				{
					cout<<"Enter the node adjacent to "<<head[i]->vertex<<": ";
					cin>>v;
					if(v==head[i]->vertex)		//self loop is not allowed
						cout<<"Self loop not allowed.";
					else
					{
						curr=new gnode;
						curr->vertex=v;
						temp->next=curr;
						temp=temp->next;
					}
					cout<<"Do you want to continue(y/n): ";
					cin>>choice;
				}
			}
		}
		void DFS_r()						//Depth first traversal of graph with recursion
		{
			for(i=0;i<n;i++)				//mark all nodes as not visited
			{
				visited[i][1]=0;
			}
			int v;
			cout<<endl<<"Enter the starting vertex: ";
			cin>>v;
			cout<<endl<<"Depth first traversal with recursion:"<<endl;
			DFS_r(v);
		}
		void DFS_r(int v)
		{
			gnode *curr;
			cout<<v<<endl;					//print the node
			for(i=0;i<n;i++)
			{
				if(visited[i][0]==v)
				{
					visited[i][1]=1;		//mark node as visited
					curr=head[i];			//assign a pointer to head of that node
					break;
				}
			}
			while(curr->next!=NULL)				//for all adjacent vertices of node,
			{						//repeat above 3 steps
				curr=curr->next;
				for(i=0;i<n;i++)
				{
					if(visited[i][0]==curr->vertex)
					{
						if(!visited[i][1])
						{
							DFS_r(curr->vertex);
							break;
						}
					}
				}
			}
		}
		void DFS_nr()
		{
			for(i=0;i<n;i++)				//mark all nodes as not visited
			{
				visited[i][1]=0;
			}
			int v;
			gnode *curr;
			stack s;
			cout<<endl<<"Enter the starting vertex: ";
			cin>>v;
			cout<<endl<<"Depth first traversal without recursion:"<<endl;
			for(i=0;i<n;i++)
			{
				if(visited[i][0]==v)
				{
					visited[i][1]=1;
					curr=head[i];
					break;
				}
			}
			cout<<curr->vertex<<endl;			//print the vertex and push it to stack
			s.push(curr);
			do
			{
				curr=s.pop();				//point the pointer to popped node
				if(curr->next!=NULL)
					s.push(curr->next);		//push next of node to stack
				curr=curr->next;
				while(curr!=NULL)			//continue for all adjacent nodes
				{
					for(i=0;i<n;i++)
					{
						if(visited[i][0]==curr->vertex)
						{
							if(!visited[i][1])
							{
								curr=head[i];	//attach pointer to head of vertex's node and print node
								cout<<curr->vertex<<endl;
								if(curr->next!=NULL)	//push next of node to stack if not NULL
									s.push(curr->next);
								visited[i][1]=1;	//mark current node as visited
								break;
							}
							else 
								break;
						}
					}
					curr=curr->next;		
				}
			}while(!s.isemp());
		}
		void BFS()						//breadth first traversal
		{
			for(i=0;i<n;i++)				//mark all nodes as not visited
			{
				visited[i][1]=0;
			}
			int v;
			gnode *curr;
			queue q;
			cout<<endl<<"Enter the starting vertex: ";
			cin>>v;
			cout<<endl<<"Breadth first traversal:"<<endl;
			for(i=0;i<n;i++)				//enqueue starting vertex and mark it as visited
			{
				if(visited[i][0]==v)
				{
					visited[i][1]=1;
					curr=head[i];			//assign pointer to head of node
					break;
				}
			}
			q.enq(curr);
			while(!q.isempq())				//continue till queue is empty
			{
				curr=q.deq();				//dequeue element and print node
				cout<<curr->vertex<<endl;
				for(i=0;i<n;i++)
				{
					if(visited[i][0]==curr->vertex)
					{
						curr=head[i];		//assign pointer to head of node
						break;
					}
				}
				while(curr!=NULL)			//enqueue all adjacent nodes 
				{
					for(i=0;i<n;i++)
					{
						if(visited[i][0]==curr->vertex)
						{
							if(!visited[i][1])
							{
								q.enq(curr);
								visited[i][1]=1;
								break;
							}
							else 
								break;
						}
					}
					curr=curr->next;	
				}
			}
		}
};


int main()
{
	graph p;
	int choice;
	while(1)
	{
		cout<<"\n********-----------MENU-----------********\n1.Create.\n2.Depth first traversal with recursion.\n3.Depth first traversal without recursion.\n4.Breadth first traversal.\n5.Exit.\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	p.create();
			break;
			case 2:	p.DFS_r();
			break;
			case 3:	p.DFS_nr();
			break;
			case 4:	p.BFS();
			break;
			case 5: exit(1);
			break;
			default:cout<<"Wrong choice!!";
		}
	}
	return 0;
}

/*
OUTPUT:

********-----------MENU-----------********
1.Create.
2.Depth first traversal with recursion.
3.Depth first traversal without recursion.
4.Breadth first traversal.
5.Exit.
Enter your choice: 1
Enter the node value: 12
Do you want to add more node(y/n): y
Enter the node value: 6
Do you want to add more node(y/n): y
Enter the node value: 2
Do you want to add more node(y/n): y
Enter the node value: 8
Do you want to add more node(y/n): y
Enter the node value: 15
Do you want to add more node(y/n): y
Enter the node value: 4
Do you want to add more node(y/n): y
Enter the node value: 1
Do you want to add more node(y/n): y
Enter the node value: 20
Do you want to add more node(y/n): n

Do you want to add node adjacent to 12 (y/n): y
Enter the node adjacent to 12: 6
Do you want to continue(y/n): y
Enter the node adjacent to 12: 8
Do you want to continue(y/n): y
Enter the node adjacent to 12: 2
Do you want to continue(y/n): n

Do you want to add node adjacent to 6 (y/n): n

Do you want to add node adjacent to 2 (y/n): y
Enter the node adjacent to 2: 6
Do you want to continue(y/n): n

Do you want to add node adjacent to 8 (y/n): y
Enter the node adjacent to 8: 15
Do you want to continue(y/n): n

Do you want to add node adjacent to 15 (y/n): y
Enter the node adjacent to 15: 12
Do you want to continue(y/n): y
Enter the node adjacent to 15: 4
Do you want to continue(y/n): n

Do you want to add node adjacent to 4 (y/n): y
Enter the node adjacent to 4: 1
Do you want to continue(y/n): y
Enter the node adjacent to 4: 20
Do you want to continue(y/n): n

Do you want to add node adjacent to 1 (y/n): y
Enter the node adjacent to 1: 20
Do you want to continue(y/n): n

Do you want to add node adjacent to 20 (y/n): n

********-----------MENU-----------********
1.Create.
2.Depth first traversal with recursion.
3.Depth first traversal without recursion.
4.Breadth first traversal.
5.Exit.
Enter your choice: 2

Enter the starting vertex: 12

Depth first traversal with recursion:
12
6
8
15
4
1
20
2

********-----------MENU-----------********
1.Create.
2.Depth first traversal with recursion.
3.Depth first traversal without recursion.
4.Breadth first traversal.
5.Exit.
Enter your choice: 3

Enter the starting vertex: 12

Depth first traversal without recursion:
12
6
8
15
4
1
20
2

********-----------MENU-----------********
1.Create.
2.Depth first traversal with recursion.
3.Depth first traversal without recursion.
4.Breadth first traversal.
5.Exit.
Enter your choice: 4

Enter the starting vertex: 12

Breadth first traversal:
12
6
8
2
15
4
1
20

********-----------MENU-----------********
1.Create.
2.Depth first traversal with recursion.
3.Depth first traversal without recursion.
4.Breadth first traversal.
5.Exit.
Enter your choice: 5
*/
