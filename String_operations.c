/*
Name: Chirantan Joshi
Div: E
Batch: E1
Roll no.: PE11
Assignment: 1
*/
#include <stdio.h>
#include <stdlib.h>
void accept(char str[20])							//Function to accept string
{
	printf("Enter the string: ");
	scanf("%s",str);
}
void delete(char str[20])							//Function to delete string
{
	str[0]='\0';
}
int length(char* string)							//Function to find length
{
	int len=0;
	while(* string!='\0')							//while loop till value in pointer is not '\0'
	{
		len++;								//Incrementing length
		*string++;							//Incrementing pointer
	}
	return len;
} 
void copy(char* src,char* dest)							//Function to copy string 
{
	while(*src!='\0')							//while loop till value in pointer is not '\0'
	{
		*dest=*src;							//storing values through pointers
		dest++;								//Incrementing pointer of destination string
		src++;								//Incrementing pointer of source string
	}
	*dest='\0';								//Ending string with '\0'
}
void concat(char* src1,char* src2)						//Function to concatenate strings
{
	printf("Enter the string that is to be concatenated with first: ");
	scanf("%s",src2);
	int v=length(src1);
	src1=src1+v;
	while(*src2!='\0')							//appending next string into first
	{
		*src1=*src2;
		src1++;
		src2++;
	}
	*src1='\0';
}
int palindrome(char string[20])							//Function to check palindrome
{	
	int n=length(string);
	int cnt=0,i;
	for(i=0;i<n/2;i++)			
	{
		if(string[i]==string[n-i-1])					//Checking first half of string with the rest half of string
		cnt++;	
	}
	if(cnt==i)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void reverse(char str[20],char str1[20])					//Function to reverse the inputted string
{
	int i,n;						
	if(palindrome(str)==0)							//Checking if string is palindrome
	{
		n=length(str);							//Calculating the string length
		for(i=0;i<n;i++)
		{
			str1[i]=str[n-i-1];					//Copying letter from end.
		}
		str1[n]='\0';
		printf("The reversed string is: %s\n",str1);
	}
	else if(palindrome(str)==1)
	{
		printf("The reversed string is: %s\n",str);
	}
}
void sub(char str[20],char str1[20])						//Function to check substring
{
	int i,j,flg;
	printf("Enter the substring to be searched: ");
	scanf("%s",str1);
	int c1=length(str),c2=length(str1);					//Calculating length of strings
	for(i=0;i<=c1-c2;i++)
	{ 
		for(j=i;j<i+c2;j++)						//loop for checking if whole string is present
		{
			flg=1;
			if (str[j]!=str1[j-i])					//Checking for same letter
			{
				flg=0;
			   	break;						//if same letter not found,break loop
			}
		}
		if (flg==1)
		break;								//When whole string is found,break loop
	}
	if (flg==1)
		printf("Given string is substring.\n");
	else
		printf("Given string is not substring. \n");
}
void compare(char str[20],char str1[20])					//Function to compare strings
{	
	int c=0;
	printf("Enter the second string: ");
	scanf("%s",str1);
	while((str[c]!='\0'&&str1[c]!='\0')&&str[c]==str1[c])			//incrementing count till the letters of string are equal
	{
		c++;
	}
	if(str[c]==str1[c])							//checking if strings are equal
		printf("The strings are equal.\n");
	else if(str[c]<str1[c])							//checking for bigger string
		printf("Second string is bigger than first string.\n");
	else
		printf("First string is bigger than second string.\n");
}
int main()
{
	int choice;
	char string[20],string1[20],conct[40];
	while(1)
	{
		printf("\n-----------Menu-----------\n\n");
		printf("1.Length of string.\n2.Copy string.\n3.Concatenate strings.\n4.Check palindrome.\n5.Compare strings.\n6.Reversing the string.\n7.Checking substring.\n8.Delete.\n9.Exit.\n\nEnter the choice: ");	//Giving different choices
		scanf("%d",&choice);
		switch(choice)							//Switch case for different choices
		{
			case 1: 
			{
				accept(string);
				printf("The length of string is: %d\n",length(string));
			}
			break;
			case 2: 
			{
				accept(string);
				copy(string,string1);
				printf("Copied String is: %s\n",string1);
			}
			break;
			case 3: 
			{
				accept(string);
				concat(string,string1);
				printf("Concatenated String is: %s\n",string);
			}
			break;
			case 4: 
			{
				accept(string);
				if(palindrome(string)==0)
				printf("The string is not palindrome\n");
				else
				printf("The string is palindrome\n");
			}
			break;
			case 5: 
			{
				accept(string);
				compare(string,string1);
			}
			break;
			case 6: 
			{
				accept(string);	
				reverse(string,string1);
			}
			break;
			case 7: 
			{
				accept(string);
				sub(string,string1);
			}
			break;
			case 8: 
			{
				accept(string);
				delete(string);
				printf("The string is deleted.\n");
			}
			break;
			case 9: exit(1);
		}
	}
	return 0;
}
