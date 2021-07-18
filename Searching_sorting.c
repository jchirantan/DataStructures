/*
Name: Chirantan P. Joshi.
Division: E
Batch: E1
Roll No.:PE11
Assignment: 3
*/
#include <stdio.h>
#include<stdlib.h>
struct student									//Structure for studenit information
{
	int rollno;
	char name[20];
	char add[10];
	float per;
};
void accept(struct student s[20],int n)						//Functon to accept the information of student 
{
	for(int i=0;i<n;i++)							//For loop for multiple entries
	{
		printf("Enter the name of student: ");
		scanf("%s",s[i].name);
		printf("Enter the Roll no. of student: ");
		scanf("%d",&s[i].rollno);
		printf("Enter the city of student: ");
		scanf("%s",s[i].add);
		printf("Enter the percentage of student: ");
		scanf("%f",&s[i].per);
	}
}
void display(struct student s[20],int n)					//Function to display the student database
{
	for(int i=0;i<n;i++)
	{
		printf("\nName of Student is: %s\n",s[i].name);
		printf("Roll no. of Student is: %d\n",s[i].rollno);
		printf("Address of Student is: %s\n",s[i].add);
		printf("Percentage of Student is: %f\n",s[i].per);
	}
}
void linear(struct student s[20],int n)						//Function for linear searching of roll no.
{
	int i,key,flag=0,loc;
	printf("\nEnter the roll no. to be searched: ");
	scanf("%d",&key);
	for(i=0;i<n;i++)							//for loop for searching in whole database
	{
		if(s[i].rollno==key)						//When match is found break for loop
		{
			flag=1;
			loc=i;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nStudent found at %dth location.\n",loc);
	}
	else
	{
		printf("\nNo student found for this roll no.Try another!\n");
	}
}
void binary(struct student s[20],int n)						//Function for binary search
{
	int key,low=0,high=n,mid,flag=0,loc;
	printf("\nEnter the roll no. to be searched: ");
	scanf("%d",&key);
	while(low<=high)							//while loop for splitting data and checking the middle value
	{
		mid=(low+high)/2;
		if(s[mid].rollno==key)
		{
			flag=1;
			loc=mid;
			break;
		}
		else if(s[mid].rollno<key)
		{
			low=mid+1;
		}
		else if(s[mid].rollno>key)
		{
			high=mid-1;
		}
	}
	if(flag==1)
	{
		printf("\nStudent found at %dth location\n",loc);
	}
	else
	{
		printf("\nNo student found for this roll no.If array is not sorted,sort it and try again!\n");
	}
}
void binaryrec(struct student s[20],int key,int high,int low)			//Function for binary search with recursion
{
	int mid,flag=0;
	mid=(low+high)/2;
	if(flag==0)
	{
		if(s[mid].rollno==key)
		{
			flag =1;
			printf("\nStudent found at %dth location\n",mid);
		}
		else if(s[mid].rollno < key)
		{
			binaryrec(s,key,high,mid+1);				//calling same function(recursion)
		}
		else
		{
			binaryrec(s,key,mid-1,low);
		}
	}
	else
	{
		printf("\nNo student found for this roll no.If array is not sorted,sort it and try again!\n");
	}
}
void bubblesort(struct student s[20],int n)					//Function for bubble sort
{
	struct student temp;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(s[j].rollno > s[j+1].rollno)
			{
				temp=s[j];					//swapping if condition is true
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	printf("\nThe Database sorted successfully!\nYou can check it by giving input 1\n");
}
void selectionsort(struct student s[20],int n)					//Function for selection sort
{
	struct student temp;
	for(int i=0;i<n-1;i++)
	{
		int minpos=i;
		for(int j=i+1;j<n;j++)
		{
			if(s[j].rollno < s[minpos].rollno)
			{
				minpos=j;
			}
		}
		if(minpos!=i)
		{
			temp=s[i];						//swapping if condition is true
			s[i]=s[minpos];
			s[minpos]=temp;
		}
	}
	printf("\nThe Database sorted successfully!\nYou can check it by giving input 1\n");
}
void insertionsort(struct student s[20],int n)					//Function for selection sort
{
	for(int i=1;i<n;i++)
	{
		struct student key=s[i];
		int j=i-1;
		while(j>=0 && s[j].rollno>key.rollno)
		{
			s[j+1]=s[j];
			j=j-1;
		}
		s[j+1]=key;
	}
	printf("Database sorted successfully!\nYou can check it by giving input 1\n");
}
int main()
{
	struct student s[20];
	int n,choice,key;
	printf("Enter the no. of students: ");
	scanf("%d",&n);
	accept(s,n);								//Calling accept function to create database
	while(1)
	{
		printf("\n--------------MENU--------------\n");
		printf("1.Display\n2.Linear search\n3.Binary search\n4.Binary search with recursion\n5.Bubble Sort\n6.Selection Sort\n7.Insertion Sort\n8.Exit\n\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)							//switch case for different inputs
		{
			case 1:display(s,n);
			break;
			case 2:linear(s,n);
			break;
			case 3:binary(s,n);
			break;
			case 4:
			{
				printf("\nEnter the roll no. to be searched: ");
				scanf("%d",&key);
				binaryrec(s,key,n-1,0);
			}
			break;
			case 5:bubblesort(s,n);
			break;
			case 6:selectionsort(s,n);
			break;
			case 7:insertionsort(s,n);
			break;
			case 8:exit(1);
		}
	}
	return 0;
}

