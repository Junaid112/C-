

#include "iostream"
#include "conio.h"
#include "string"
using namespace std;
int main()
{
	char pass='a',pass2[50];
	string passwrd (""),passes("");
	while(pass!=13)
	{
		pass=getch();
		if(pass!=13)
			{
				passes=passes+pass;
		cout<<"*";
		    }
		else cout<<"\n";
	}
	 pass='a';
	while(pass!=13)
	{
		pass=getch();
		if(pass!=13)
			passwrd=passwrd+pass;
		cout<<"*";
	}
	if(passwrd.compare(passes)==0)
		cout<<"\nPassword Match";
	else cout<<"\nPassword Mismatch";
}