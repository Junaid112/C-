
#include "iostream"
#include "conio.h"
#include "string"
using namespace std;
int main()
{
	char pass='a',pass2[50];
	string passwrd (""),passes="junaid";
	while(pass!=13)
	{
		pass=getch();
		if(pass!=13)
			passwrd=passwrd + pass;
		cout<<"*";
	}
	if(passwrd.compare(passes)==0)
		cout<<"\nPassword Match";
	else cout<<"\nPassword Missmatch";
	
}