/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
POLYNOMIAL OPERATIONS WITH CLL
*/
#include <iostream>
#include <math.h>
using namespace std;
class term							//Class for a term in polynomial
{
	int coef,expo;
	term *next;
    public:
	friend class poly;					//Making polynomial class as friend of term class
};
class poly							//Class polynomial for operations on polynomial
{
	term *head=new term;
    public:
	poly()							//constructor for initialization 
	{
		head->next=head;
		head->coef=0;
		head->expo=-1;
	}
	void create();						//Functions that are to be applied
	void display();
	void addpoly(poly p1,poly p2);
	void eval(int x,poly p);
};
void poly::create()						//To create new polynomial
{
	int cnt=0;
	char choice;
	term *temp,*curr,*temp1,*temp2;
	temp=head;
	do							//loop for creating different terms
	{
		curr=new term;					//allocate memory by "new"
		cout<<"Enter the coefficient: ";
		cin>>curr->coef;
		cout<<"Enter the exponent: ";			//storing values to current pointer
		cin>>curr->expo;
		temp->next=curr;
		curr->next=head;				//temporory pointer to traverse through polynomial
		temp=temp->next;
		temp1=head->next;
		for(int i=0;i<cnt;i++)
		{
			if((curr->expo > temp1->expo)&&(temp1!=head))
			{
				temp2->coef=curr->coef;
				temp2->expo=curr->expo;
				curr->coef=temp1->coef;
				curr->expo=temp1->expo;
				temp1->coef=temp2->coef;
				temp1->expo=temp2->expo;
			}
			temp1=temp1->next;
		}
		cnt++;
		cout<<"Do you want to add more terms?(y/n): ";	
		cin>>choice;
	}while(choice=='y');
	
}
void poly::display()						//To display polynomial
{
	term *temp;						//temporary pointer to traverse through polynomial
	temp=head->next;
	cout<<endl<<"The polynomial is: ";
	while(temp!=head)
	{
		cout<<temp->coef;				//displaying polynomial
		if(temp->expo!=0 && temp->expo!=1)
			cout<<"x^"<<temp->expo;
		else if(temp->expo==1)
			cout<<"x";
		if(temp->next != head && temp->next->coef >= 0)
			cout<<" + ";
		else if(temp->next->coef < 0)
			cout<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void poly::addpoly(poly p1,poly p2)				//To add 2 polynomials
{
	poly p3;
	term *t1,*t2,*t3,*t4;					//t1,t2 pointers to traverse 2 polynomial 
	t1=p1.head->next;
	t2=p2.head->next;
	t4=p3.head;						//t3,t4 pointers to maintain 3rd(result)polynomial
	while(t1!=p1.head || t2!=p2.head)
	{
		t3=new term;
		if(t1->expo==t2->expo)				//taking different conditions w.r.t. exponents
		{
			t3->coef=t1->coef + t2->coef;
			t3->expo=t1->expo;
			t4->next=t3;
			t3->next=p3.head;
			t4=t4->next;
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->expo > t2->expo)
		{
			t3->coef=t1->coef;
			t3->expo=t1->expo;
			t4->next=t3;
			t3->next=p3.head;
			t4=t4->next;
			t1=t1->next;
		}
		else if(t1->expo < t2->expo)
		{
			t3->coef=t2->coef;
			t3->expo=t2->expo;
			t4->next=t3;
			t3->next=p3.head;
			t4=t4->next;
			t2=t2->next;
		}
	}
	cout<<endl<<"After addition,";
	p3.display();						//Displaying result polynomial
}
void poly::eval(int val,poly p)					//To evaluate the polynomial by given value
{
	int sum=0,res;
	term *curr=p.head->next;
	while(curr!=head)
	{
		res=(curr->coef)*(pow(val,curr->expo));		//Evaluating terms one by one,with pow inbuilt function
		sum+=res;					//summing all the terms
		curr=curr->next;
	}
	cout<<"The result after polynomial evaluation is: "<<sum<<endl;
}
int main()
{
	int val,choice;
	while(1)
	{
		poly p1,p2,p3;
		cout<<"\n-----------MENU-----------\n\n1.Create and Display.\n2.Add.\n3.Evaluate.\n4.Exit.\nEnter the choice: ";
		cin>>choice;					//Taking choice for different operations
		switch(choice)
		{
			case 1:	cout<<"Enter the polynomial."<<endl;
				p1.create();
				p1.display();
			break;
			case 2:	cout<<"Enter the first polynomial."<<endl;
				p1.create();
				cout<<endl<<"Enter the second polynomial."<<endl;
				p2.create();	
				p1.display();	
				p2.display();
				p3.addpoly(p1,p2);
			break;
			case 3:	cout<<"Enter the polynomial."<<endl;
				p1.create();
				p1.display();
				cout<<"Enter the value for variable: ";
				cin>>val;
				p1.eval(val,p1);
			break;
			case 4: exit(1);
			break;
			default:cout<<"Wrong choice!!\nEnter the valid choice.\n";
		}
	}
	return 0;
}
/*
OUTPUT:

-----------MENU-----------

1.Create and Display.
2.Add.
3.Evaluate.
4.Exit.
Enter the choice: 1
Enter the polynomial.
Enter the coefficient: 3
Enter the exponent: 2
Do you want to add more terms?(y/n): y
Enter the coefficient: 4
Enter the exponent: 1
Do you want to add more terms?(y/n): y
Enter the coefficient: 7
Enter the exponent: 0
Do you want to add more terms?(y/n): n

The polynomial is: 3x^2 + 4x + 7

-----------MENU-----------

1.Create and Display.
2.Add.
3.Evaluate.
4.Exit.
Enter the choice: 2
Enter the first polynomial.
Enter the coefficient: 2
Enter the exponent: 5
Do you want to add more terms?(y/n): y
Enter the coefficient: 3
Enter the exponent: 2
Do you want to add more terms?(y/n): y
Enter the coefficient: 1
Enter the exponent: 0
Do you want to add more terms?(y/n): n

Enter the second polynomial.
Enter the coefficient: 2
Enter the exponent: 6
Do you want to add more terms?(y/n): y
Enter the coefficient: 5
Enter the exponent: 5
Do you want to add more terms?(y/n): y
Enter the coefficient: 3
Enter the exponent: 3
Do you want to add more terms?(y/n): y
Enter the coefficient: 9
Enter the exponent: 0
Do you want to add more terms?(y/n): n

The polynomial is: 2x^5 + 3x^2 + 1

The polynomial is: 2x^6 + 5x^5 + 3x^3 + 9

After addition,
The polynomial is: 2x^6 + 7x^5 + 3x^3 + 3x^2 + 10

-----------MENU-----------

1.Create and Display.
2.Add.
3.Evaluate.
4.Exit.
Enter the choice: 3
Enter the polynomial.
Enter the coefficient: 4
Enter the exponent: 3
Do you want to add more terms?(y/n): y
Enter the coefficient: 6
Enter the exponent: 2
Do you want to add more terms?(y/n): y
Enter the coefficient: -2
Enter the exponent: 1
Do you want to add more terms?(y/n): y
Enter the coefficient: 7
Enter the exponent: 0
Do you want to add more terms?(y/n): n

The polynomial is: 4x^3 + 6x^2 -2x + 7
Enter the value for variable: 3
The result after polynomial evaluation is: 163

-----------MENU-----------

1.Create and Display.
2.Add.
3.Evaluate.
4.Exit.
Enter the choice: 4

*/
