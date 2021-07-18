/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
HEAP SORT
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class heaps										//Class heap
{
		int marks[20],marksd[20];
	public:
		void accept(int n)							
		{
			for(int i=0;i<n;i++)
			{
				cout<<"Enter the marks obtained by student "<<i+1<<": ";//Accept the marks of students 
				cin>>marks[i];
				marksd[i]=marks[i];
			}
		}
		void display(int len)
		{
			cout<<endl<<"The marks in ascending order is as follows: \n";		
			for(int i=0;i<len;i++)						//Display the marks in ascending order
			{
				cout<<marks[i]<<"\t";
			}
			cout<<endl<<"The marks in descending order is as follows: \n";
			for(int i=0;i<len;i++)						//Display the marks in descending order
			{
				cout<<marksd[i]<<"\t";
			}
			cout<<endl<<endl<<"Maximum marks obtained are: "<<marksd[0]<<endl;
			cout<<"Minimum marks obtained are: "<<marks[0]<<endl;
		}
		void heapsort(int n)								
		{	
			int temp,i,n1=n;
			for(i=n/2-1;i>=0;i--)
			{
				adjustmax(n,i);						//Adjust the array in max heap order
				adjustmin(n,i);						//Adjust array in min heap order
			}
			while(n>0)
			{
				temp=marks[0];						//as we have the smallest element at root,
				marks[0]=marks[n-1];					//Swap it with last element in array and fix it
				marks[n-1]=temp;
				n--;
				adjustmax(n,0);						//Adjust the remaining elements in max heap order
			}								//reheap down
			while(n1>0)
			{	
				temp=marksd[0];						//as we have the smallest element at root,
				marksd[0]=marksd[n1-1];					//Swap it with last element in array and fix it
				marksd[n1-1]=temp;
				n1--;
				adjustmin(n1,0);					//Adjust the remaining elements in min heap order
			}								//reheap down
		}
		void adjustmax(int n,int i)						//Function to arrange tree in max heap
		{
			int temp,j;
			while((2*i)<n-1)
			{
				j=2*i;
				if((j<=n)&&(marks[j+1]>marks[j]))			//if next element is greater than j
					j=j+1;						//assign j to next element
				if(marks[i]>=marks[j])					//if parent is greater than greater child
					break;						//break
				else							//else swap the child with parent
				{
					temp=marks[i];
					marks[i]=marks[j];
					marks[j]=temp;
					i=j;						//assign value of j to i
				}							//as all below elements are in max heap order
			}
		}
		void adjustmin(int n,int i)						//Function to arrange tree in min heap
		{
			int temp,j;
			while((2*i)<n-1)
			{
				j=2*i;
				if((j<=n)&&(marksd[j+1]<marksd[j]))			//if next element is less than j
					j=j+1;						//assign j to next element
				if(marksd[i]<=marksd[j])				//if parent is less than lesser child,break
					break;						
				else							//else swap the child with parent
				{
					temp=marksd[i];
					marksd[i]=marksd[j];
					marksd[j]=temp;
					i=j;						//assign value of j to i
				}							//as all below elements are in min heap order
			}
		}
};

int main()
{
	int n;
	cout<<"Enter the number of students: ";						//Accept the number of students 
	cin>>n;
	heaps h;
	h.accept(n);
	h.heapsort(n);
	h.display(n);
	return 0;
}

/*
OUTPUT:
Enter the number of students: 5
Enter the marks obtained by student 1: 12
Enter the marks obtained by student 2: 34
Enter the marks obtained by student 3: 56
Enter the marks obtained by student 4: 7
Enter the marks obtained by student 5: 1

The marks in ascending order is as follows: 
1	7	12	34	56	
The marks in descending order is as follows: 
56	34	12	7	1	

Maximum marks obtained are: 56
Minimum marks obtained are: 1
*/
