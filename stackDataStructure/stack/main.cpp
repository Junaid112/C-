#include<iostream>
using namespace std;
#include"Stack.h"
#include<cstring>



char* postFix(char*);
int precedens(char op)
{
	if(op=='-')
		return 0;
	else if(op=='+')
		return 1;
	else if(op=='*')
		return 2;
	else if(op=='/')
		return 3;
	else
		return 0;
}
int main()
{
	try
	{
		
		char exp1[10]="a-b+d/c";
		
		cout<<postFix(exp1);
		
	}
	catch(exception obj)
	{
		cout<<obj.what()<<endl;
	}
}

char* postFix(char* a)
{
	int count=0;
	Stack <char> stak(20);
	char *b=new char[strlen(a)+1];
	//b[0]=a[0];
	for(int i=0;i<=strlen(a);i++)
	{
		if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/' && a[i]!='(' && a[i]!=')')
		{
			b[count]=a[i];
			count++;
		}
		else if (a[i]!='+' || a[i]!='-' || a[i]!='*' || a[i]!='/' )
		{
			while (!stak.isEmpty() && precedens(stak.StackTop()) > precedens())
			{
			pop the operator from stack and append it to postfix_string
			}
			if ( next_character is not ‘)’ )
			{
			push next_character to stack
			}
			else if ( next_character is ‘)’ )
			{
			pop from stack //it will pop ‘(‘ bracket
			}
		}




		}
	}
		
	return b;
}
	


/*

if(a[i]=='+'|| a[i]=='-'|| a[i]=='*'|| a[i]=='/')
		stak.push(a[i]);
		else
		{
			b[count]=a[i];
			count++;
		}
	}
	char op1,op2;
	for(int i=0;i<=stak.getTheNoOfElements();i++)
	{

		op1=stak.pop();
		if(!stak.isEmpty())
		{
			b[count-1]=op1;
			count++;
		}
		else if(op1=='/')
		{
			b[count-1]=op1;
			count++;
		}
		else if(op1=='*')
		{
			op2=stak.StackTop();
			if(op2=='/')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='*')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='+')
				{
					b[count-1]=op1;
					count++;
				}
			if(op2=='-')
				{
					b[count-1]=op1;
					count++;
				}
		}
		else if(op1=='+')
		{
			op2=stak.StackTop();
			if(op2=='/')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='*')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='+')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='-')
				{
					b[count-1]=op1;
					count++;
				}
		}
		else if(op1=='-')
		{
			op2=stak.StackTop();
			if(op2=='/')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='*')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='+')
				{
					b[count-1]=op2;
					count++;
				}
			if(op2=='-')
				{
					b[count-1]=op1;
					count++;
				}
		}
	}
	b[count-1]=op1;
	b[count]='\0';*/