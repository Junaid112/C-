

#include<iostream>
#include"MyString.h"
#include<cstring>
#include<stdexcept>
#include<fstream>
using namespace std;




MyString::MyString()
{
	strLength=0;
	str=new char[strLength+1];
	str[0]='\0';

}
MyString::MyString(const char *strn)
{
	strLength=strlen(strn);
	str=new char[strLength+1];
	strcpy(str,strn);
	//for(int i=0; i<strLength;i++)
	//{
		//str[i]=strn[i];
	//};
}
MyString::MyString(const MyString &str1)
{
	strLength=str1.strLength;
	str=new char[strLength+1];

	strcpy(str,str1.str);
	/*for(int i=0; i<strLength;i++)
	{
		str[i]=str1.str[i];
	};*/
}
void MyString::display ()
{
	cout<<str;
	/*for(int i=0; i<strLength;i++)
	{
		cout<<str[i];
	};
	*/
}
int MyString::getLength ()
{


	return strlen(str);
}
const MyString& MyString::operator= (const MyString& s2)
{
	if(str!=0)
	{
		delete [] str;
		str=0;
	}
	strLength=s2.strLength;
	str=new char[strLength+1];
	strcpy(str,s2.str);
	return *this;
}

 MyString::~MyString()
 {
	 if(str!=0)
	 {
		 delete [] str;
	 }

 }
 
 

const MyString& MyString::operator= (int n)
{


	
	   int num=n,i=0;
	   while(n>0)
	   {
		   n=n/10;
		   i++;
	   }
	   str=new char [i+1];
	   str=itoa(num,str,10);
	   strLength=i+1;
	
	return *this;
}
// Destructor 

 
  MyString& MyString::operator ++ ()
  {
	  for(int i=0;i<strLength;i++)
	  {
		  str[i]=toupper(str[i]);
	  }
	  return *this;
  }
   MyString MyString:: operator - (char a)
   {
	   int count=0;
	    for(int i=0;i<=strLength;i++)
	  {
		 if(str[i]==a)
		 {
			 count=count+1;
		 }
	  }
	   MyString temp;
	   if(temp.str!=0)
	   {
		   delete [] temp.str;
		   temp.str=0;
	   }
	   temp.strLength=strLength-count;
	   temp.str=new char [ temp.strLength+1];
	   int j=0;
	   for(int i=0;i<=strLength;i++)
	  {

		 if(str[i]!=a)
		 {
			 temp.str[j]=str[i];
			 j=j+1;
		 }
	  }

	   return temp;

   }
 MyString::MyString(int n)
   {
	   int num=n,i=0;
	   while(n>0)
	   {
		   n=n/10;
		   i++;
	   }
	   str=new char [i+1];
	   str=itoa(num,str,10);
	   strLength=i+1;
   }


 char MyString::operator [](int idx)
 {
	 if(idx<0 || idx>strLength)
	 {
		throw exception("**ERROR !");
	 }

	 return str[idx];
 }
   MyString& MyString::operator -- (int)
  {
	  for(int i=0;i<strLength;i++)
	  {
		  str[i]=tolower(str[i]);
	  }
	  return *this;
  }
  
   MyString& MyString:: operator -= (char a)
   {
	   int count=0;
	    for(int i=0;i<=strLength;i++)
	  {
		 if(str[i]==a)
		 {
			 count=count+1;
		 }
	  }
	   MyString temp=*this;
	   strLength=strLength-count;
	   str=new char [ temp.strLength+1];
	   int j=0;
	   for(int i=0;i<=strLength;i++)
	  {

		 if(temp.str[i]!=a)
		 {
			 str[j]=temp.str[i];
			 j=j+1;
		 }
	  }
	   str[j]='\0';
	    
	   return *this;

   }
 MyString  MyString::operator! ()
{
	MyString temp=*this;
	int i=strlen(str)-1;
	for(int j=0;j<temp.strLength;j++)
	{
		temp.str[j]=str[i];
		i--;
	}

	return temp;
}

