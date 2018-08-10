#include<iostream>
#include<stdexcept>
using namespace std;
#ifndef ARRAY_H
#define ARRAY_H

class Array;
ostream& operator <<(ostream& out,const Array &);
istream& operator >>(istream& in, Array&);
ifstream& operator >>(ifstream& in, Array&);
class Array
{
private:
	char *data;
	int size;
	int isValidIndex(int i);

public:
	 Array(int = 30);
	 Array(const Array &);
	 Array & operator = (const Array &);
	 char & operator [] (int i);
	 void reSize(int = 5);
	 void removeChar(char );
	 int getNoOfChar()const;
	 int getNoOfCharWithSpace()const;
	 bool ismember (char );
	 bool isAnagram(Array&);

	 friend ostream& operator <<(ostream& out,const Array &);
     friend istream& operator >>(istream& in, Array&);
	 friend ifstream& operator >>(ifstream& in, Array&);
	 ~Array();
	
};
#endif

