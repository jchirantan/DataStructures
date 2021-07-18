/*
Name: Chirantan Joshi
Div: E
Batch: E1
Roll no.: PE11
Assignment: 2
*/
#include <stdio.h>
#include <stdlib.h>
void display(int A[10][3],int m)						//Display function to display matrices
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
void compact(int A[6][6],int m,int n,int B[10][3])				//Function to convert sparse matrix to compact form
{
	int i,j;
	B[0][0]=m;								//Storing no. of rows
	B[0][1]=n;								//Storing no. of columns
	int k=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j]!=0)						//Checking for non zero elements
			{
				B[k][0]=i;					//Storing non zero elements with row and column index
				B[k][1]=j;
				B[k][2]=A[i][j];
				k++;
			}
		}
	}
	B[0][2]=k-1;								//Storing no. of non zero elements
}
void simpletranspose(int A[10][3],int B[10][3])					//Function for simple transpose
{
	int i,j,k,n;
	B[0][0]=A[0][1];							//Changing no. of row and no. of columns
	B[0][1]=A[0][0];
	B[0][2]=A[0][2];
	k=1;
	n=A[0][2]+1;
	for(i=0;i<A[0][1];i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==A[j][1])						//Arranging column index in ascending order
			{
				B[k][0]=i;
				B[k][1]=A[j][0];				//Swapping column with row index and storing value associated
				B[k][2]=A[j][2];
				k++;
			}
		}
	}
}
void fasttranspose(int A[10][3],int B[10][3])					//Function for fast transpose
{
	int i,j,t,loc;
	int total[7],index[7];	
	B[0][0]=A[0][1];
	B[0][1]=A[0][0];
	B[0][2]=A[0][2];
	t=A[0][2];
	for(i=0;i<A[0][1];i++)							//Initializing total array to 0
	{
		total[i]=0;
	}
	for(i=1;i<=t;i++)							//Creating total array
	{
		j=A[i][1];
		total[j]=total[j]+1;
	}
	index[0]=1;								//Creating index array
	for(i=1;i<=A[0][1];i++)
	{
		index[i]=index[i-1]+total[i-1];
	}
	for(i=1;i<=t;i++)							//Storing the transposed values at specified index
	{
		j=A[i][1];
		loc=index[j];
		index[j]++;
		B[loc][0]=A[i][1];
		B[loc][1]=A[i][0];
		B[loc][2]=A[i][2];
	}
}
int main()
{
	int A[6][6],i,j,row,col,B[10][3],C[10][3],D[10][3],choice;
	printf("Enter the no. of rows: ");
	scanf("%d",&row);
	printf("Enter the no. of columns: ");
	scanf("%d",&col);
	for(i=0;i<row;i++)							//Taking Input for sparse matrix
	{
		for(j=0;j<col;j++)
		{
			printf("Enter the value at %d,%d position: ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	compact(A,row,col,B);							//Calling compact function
	while(1)
	{
		printf("\n-----------MENU-----------\n");
		printf("1.Original Matrix.\n2.Sparse compact matrix.\n3.Simple transpose.\n4.Fast transpose.\n5.Exit.\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)							//Switch case for different options
		{
			case 1:
			{
				printf("\nYour Matrix is: \n");
				for(i=0;i<row;i++)
				{
					for(j=0;j<col;j++)
					{
						printf("%d\t",A[i][j]);
					}
					printf("\n");
				}
			}
			break;
			case 2:
			{
				printf("\nSparse matrix compact form is: \n");
				display(B,B[0][2]+1);
			}
			break;
			case 3:
			{

				simpletranspose(B,C);				//Calling simple transpose function
				printf("\nSimple transpose of Sparse matrix is: \n");
				display(C,C[0][2]+1);				//Displaying transposed matrix
			}
			break;
			case 4:
			{

				fasttranspose(B,D);				//Calling fast transpose function
				printf("\nFast transpose of Sparse matrix is: \n");
				display(D,D[0][2]+1);				//Displaying transposed matrix
			}
			break;
			case 5: exit(1);
		}
	}
	return 0;
}

