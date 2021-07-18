/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
PRIMS ALGORITHM
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class spanning
{
		int cost[10][10];							//Store cost adjacency matrix
		int prims[10][3];							//Store final tree
		int near[10];								//Near array
		int n,i,j;
	public:
		spanning()								//Initializing near array to 0
		{
			near[10]={0};
		}
		void accept()
		{
			cout<<"Enter the total number of vertices: ";			//Accept the number of vertices 
			cin>>n;
			cout<<endl<<"(NOTE:If no edge exists,enter cost as 999.)"<<endl;
			for(i=0;i<n;i++)						//Accept the edge cost for each edge
			{
				for(j=0;j<n;j++)
				{							//Consider infinity as 999
					cout<<"Enter the cost of edge "<<i<<"-"<<j<<": ";
					cin>>cost[i][j];
				}
			}
		}
		void Prims()
		{
			int startv,nearv,minimum=0,min,r=0;
			cout<<endl<<"Enter the starting vertex: ";
			cin>>startv;
			near[startv]=-1;						//Mark starting vertex as visisted
			for(i=0;i<n;i++)
			{
				if(i!=startv)						//Mark all the remaining vertices'
					near[i]=startv;					//near as starting
			}								 
			for(i=1;i<n;i++)						//continue till all nodes are visited
			{
				min=999;
				for(j=0;j<n;j++)
				{
					if(near[j]!=-1 && cost[j][near[j]]<min)		//Find minimum cost edge
					{						//By compairing cost of cost adjacency matrix
						nearv=j;				//store the nearest vertex in nearv
						min=cost[j][near[j]];
					}
				}
				prims[r][0]=near[nearv];				//store near of near vertex,near vertex and
				prims[r][1]=nearv;					//cost associated in final tree
				prims[r][2]=min;
				r++;
				minimum+=min;						//Update minimum cost
				near[nearv]=-1;						//mark nearv as visited
				for(j=0;j<n;j++)
				{							//Update near matrix by compairing
					if(near[j]!=-1 && cost[j][near[j]]>cost[j][nearv])//cost of near vertex with cost adjacency matrix 
						near[j]=nearv;
				}
			}
			cout<<"The minimum cost possible is: "<<minimum<<endl;		//Display the minimum cost possible
			cout<<endl<<"vertex1\t\tvertex2\t\tcost"<<endl;			//And final tree
			for(i=0;i<n-1;i++)
			{
				cout<<prims[i][0]<<"\t\t"<<prims[i][1]<<"\t\t"<<prims[i][2]<<endl;
			}
		}
};

int main()
{
	spanning route;
	route.accept();
	route.Prims();
	return 0;
}

/*
OUTPUT:
Enter the total number of vertices: 5

(NOTE:If no edge exists,enter cost as 999.)
Enter the cost of edge 0-0: 999
Enter the cost of edge 0-1: 8
Enter the cost of edge 0-2: 4
Enter the cost of edge 0-3: 10
Enter the cost of edge 0-4: 999
Enter the cost of edge 1-0: 8
Enter the cost of edge 1-1: 999
Enter the cost of edge 1-2: 9
Enter the cost of edge 1-3: 999
Enter the cost of edge 1-4: 5
Enter the cost of edge 2-0: 4
Enter the cost of edge 2-1: 9
Enter the cost of edge 2-2: 999
Enter the cost of edge 2-3: 12
Enter the cost of edge 2-4: 6
Enter the cost of edge 3-0: 10
Enter the cost of edge 3-1: 999
Enter the cost of edge 3-2: 12
Enter the cost of edge 3-3: 999
Enter the cost of edge 3-4: 7
Enter the cost of edge 4-0: 999
Enter the cost of edge 4-1: 5
Enter the cost of edge 4-2: 6
Enter the cost of edge 4-3: 7
Enter the cost of edge 4-4: 999

Enter the starting vertex: 0
The minimum cost possible is: 22

vertex1		vertex2		cost
0		2		4
2		4		6
4		1		5
4		3		7
*/
