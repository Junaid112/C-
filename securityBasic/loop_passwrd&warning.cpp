

#include "iostream"
#include "conio.h"
#include "string"
using namespace std;
int main()
{
	int c=1;
	char pass='a',pass2[50];
	string passwrd (""),passes="junaid";
	for(c=1;c<=5;c++)
	{
		if(c>1)
			cout<<"\nTry Again: ";
	cout<<"Type Password: ";

	while(pass!=13)
	{
		pass=getch();
		if(pass!=13)
		{
		passwrd=passwrd + pass;
		cout<<"*";
		}
	}
	if(passwrd.compare(passes)==0)
	
		cout<<"\nPassword Match\n";
	    
	else 
		{
			cout<<"\nPassword Missmatch\n";
			
			pass='a';
			passwrd ="";
	    }
	if(passwrd.compare(passes)==0)
	break;
	}
	if(c==6)
	{
		cout<<"\nYou tried 5 Times \n";
		cout<<"\nYou are a illegal person close this program Else i have to call Police\n ";
	}
	else cout<<"\nYou are a Authorised User\n";
}