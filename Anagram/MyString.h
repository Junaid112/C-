#include<fstream>
#include<iostream>

using namespace std;
#ifndef MYSTRING_H
#define MYSTRING_H

class MyString;
ostream& operator <<(ostream& out,const MyString &);
istream& operator >>(istream& in, MyString&);

 
class MyString 
{ 
	
private: 
char *str;   // Pointer to the char array that holds the string 
int strLength;   // Variable to store the length of the string // max length
 
public: 
// Default constructor to initialize the string to empty string 
MyString(); 
 
// Overloaded constructor 
MyString(const char *); 
 
// Copy constructor 
MyString(const MyString&); 
 
 MyString(int);
// Display the string on screen 
void display (); 
 
// Returns the length (# of characters excluding the null terminator) of the string 
int getLength (); 
 
// Overloaded assignment operator 
const MyString& operator = (const MyString&); 
 
// Destructor 
~MyString(); 

MyString& operator ++ (); 
MyString operator - (char);
const MyString& operator= (int );

char operator [](int);
MyString& operator -- (int); 
MyString& operator -= (char);
MyString operator! ();
bool isMember(char );
bool isAnagram(MyString &);



friend ostream& operator <<(ostream& out,const MyString&);
friend istream& operator >>(istream& in, MyString&);

}; 
 
#endif;




