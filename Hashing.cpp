/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
STUDENT RECORDS BY HASHING
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define max 10

class student
{
		int rollno;							//Different fields for student
		string name;
		string grade;
	public:
		student()							//initializing the fields
		{
			rollno=-1;
			name="-";
			grade="-";	
		}
		friend class hashs;	
};
class hashs
{
		student hashtable[max];
		int i;
	public:
		hashs()								//Making all roll no. entries in hashtable as -1
		{
			for(i=0;i<max;i++)
			{
				hashtable[i].rollno=-1;
			}
		}
		void display()							//Displaying hash table
		{
			cout<<"\nINDEX\tROLL_NO\tNAME\tGRADE\n";
			for(i=0;i<max;i++)
			{
				cout<<i<<"\t";
				cout<<hashtable[i].rollno<<"\t";
				cout<<hashtable[i].name<<"\t ";
				cout<<hashtable[i].grade<<"\n";
			}
		}
		void linear_wor()						//linear probing without replacement
		{
			student s;
			char ch='y';
			int index=0;
			while(ch=='y')
			{
				cout<<"Enter the roll no.: ";			//Accepting the student attributes
				cin>>s.rollno;
				cout<<"Enter the Name: ";
				cin>>s.name;
				cout<<"Enter the Grade: ";
				cin>>s.grade;
				index=s.rollno%max;
				if(hashtable[index].rollno==-1)			//Checking if roll no. in hash table is -1
					hashtable[index]=s;			//if yes add student directly in table
				else						//else
				{
					i=1;					//add student at next empty location in table
					i=(index+i)%max;
					while(i!=index)
					{
						if(hashtable[i].rollno==-1)
						{
							hashtable[i]=s;
							break;
						}
						i=(i+1)%max;
					}
					if(i==index)				//if all the locations are filled,warn user
						cout<<endl<<"Hash is full!!"<<endl<<endl;
				}
				cout<<"Do you want to add more entries(y/n)? ";
				cin>>ch;
			}
			display();						//display the table
		}
		void linear_wr()						//linear probing with replacement
		{
			student s,temp;
			char ch='y';
			int index=0;
			while(ch=='y')						
			{		
				cout<<"Enter the roll no.: ";			//Accept the attributes of student
				cin>>s.rollno;
				cout<<"Enter the Name: ";
				cin>>s.name;
				cout<<"Enter the Grade: ";
				cin>>s.grade;
				index=s.rollno%max;
				if(hashtable[index].rollno==-1)			//Checking if roll no. in hash table is -1
					hashtable[index]=s;			//if yes add student directly in table
				else						//else
				{
					temp=s;					//store the attributes at a temporary variable
					if(index!=hashtable[index].rollno%max)	//if the location is already filled 
					{
						temp=hashtable[index];		//store the attribute stored at that location in temp
						hashtable[index]=s;		//store the attributes of new student at that location
					}
					i=(index+1)%max;
					while(i!=index)				//store that temp at next empty location in table
					{
						if(hashtable[i].rollno==-1)
						{
							hashtable[i]=temp;
							break;
						}
						i=(i+1)%max;
					}
					if(i==index)				//if all the locations are filled,warn user
						cout<<endl<<"Hash is full!!"<<endl<<endl;
				}
				cout<<"Do you want to add more entries(y/n)? ";
				cin>>ch;	
			}
			display();						//Display hash table
		}
		
};

int main()
{
	hashs h1,h2;
	int val,choice;
	while(1)
	{
		cout<<"\n------------------MENU------------------\n\n1.Linear Probing without replacement.\n2.Linear Probing with replacement.\n3.Exit.\nEnter the choice: ";
		cin>>choice;							//Taking choice for different operations
		switch(choice)
		{
			case 1:	h1.linear_wor();
			break;
			case 2:	h2.linear_wr();
			break;
			case 3: exit(1);
			break;
			default:cout<<"Wrong choice!!\nEnter the valid choice.\n";
		}
	}
	return 0;
}
/*
OUTPUT:

------------------MENU------------------

1.Linear Probing without replacement.
2.Linear Probing with replacement.
3.Exit.
Enter the choice: 1
Enter the roll no.: 1
Enter the Name: Ram
Enter the Grade: A+
Do you want to add more entries(y/n)? y
Enter the roll no.: 11
Enter the Name: Raghav
Enter the Grade: A
Do you want to add more entries(y/n)? y
Enter the roll no.: 22
Enter the Name: Krishna
Enter the Grade: B
Do you want to add more entries(y/n)? y
Enter the roll no.: 45 
Enter the Name: Vishnu
Enter the Grade: B+
Do you want to add more entries(y/n)? n

INDEX	ROLL_NO	NAME	GRADE
0	-1	-	 -
1	1	Ram	 A+
2	11	Raghav	 A
3	22	Krishna	 B
4	-1	-	 -
5	45	Vishnu	 B+
6	-1	-	 -
7	-1	-	 -
8	-1	-	 -
9	-1	-	 -

------------------MENU------------------

1.Linear Probing without replacement.
2.Linear Probing with replacement.
3.Exit.
Enter the choice: 2
Enter the roll no.: 1
Enter the Name: Ram
Enter the Grade: A+
Do you want to add more entries(y/n)? y
Enter the roll no.: 11
Enter the Name: Raghav
Enter the Grade: A
Do you want to add more entries(y/n)? y
Enter the roll no.: 10
Enter the Name: Shyam
Enter the Grade: B
Do you want to add more entries(y/n)? y
Enter the roll no.: 22
Enter the Name: Vishnu   
Enter the Grade: B+
Do you want to add more entries(y/n)? y
Enter the roll no.: 20
Enter the Name: Krishna
Enter the Grade: A
Do you want to add more entries(y/n)? y
Enter the roll no.: 35
Enter the Name: Raghu
Enter the Grade: B
Do you want to add more entries(y/n)? y
Enter the roll no.: 24
Enter the Name: Samar
Enter the Grade: F
Do you want to add more entries(y/n)? n

INDEX	ROLL_NO	NAME	GRADE
0	10	Shyam	 B
1	1	Ram	 A+
2	22	Vishnu	 B+
3	11	Raghav	 A
4	24	Samar	 F
5	35	Raghu	 B
6	20	Krishna	 A
7	-1	-	 -
8	-1	-	 -
9	-1	-	 -

------------------MENU------------------

1.Linear Probing without replacement.
2.Linear Probing with replacement.
3.Exit.
Enter the choice: 2
Enter the roll no.: 17
Enter the Name: Somnath
Enter the Grade: C+
Do you want to add more entries(y/n)? y
Enter the roll no.: 26
Enter the Name: Ramraj         
Enter the Grade: C
Do you want to add more entries(y/n)? y
Enter the roll no.: 18
Enter the Name: Ganesh
Enter the Grade: D 
Do you want to add more entries(y/n)? y
Enter the roll no.: 19
Enter the Name: Raja 
Enter the Grade: D

Hash is full!!

Do you want to add more entries(y/n)? n

INDEX	ROLL_NO	NAME	GRADE
0	10	Shyam	 B
1	1	Ram	 A+
2	22	Vishnu	 B+
3	11	Raghav	 A
4	24	Samar	 F
5	35	Raghu	 B
6	26	Ramraj	 C
7	17	Somnath	 C+
8	18	Ganesh	 D
9	19	Raja	 D

------------------MENU------------------

1.Linear Probing without replacement.
2.Linear Probing with replacement.
3.Exit.
Enter the choice: 3
*/
