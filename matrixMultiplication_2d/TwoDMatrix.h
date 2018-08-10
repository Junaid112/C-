// BSEF11M026
// JUNAID AHMED GHAURI


#include<fstream> //input file stream
using namespace std;
#ifndef TWODMATRIX_H
#define TWODMATRIX_H

class TwoDMatrix;
ostream& operator <<(ostream& out,const TwoDMatrix &); //overloading exersion operator
istream& operator >>(istream& in, TwoDMatrix&); //overloading insersion operator
ifstream& operator >>(ifstream& fin, TwoDMatrix&); //overloading insersion operator
class TwoDMatrix
{
private:			//private variable
	int **ptr;
	int nr; // number of rows
	int nc;	// number of column
public:
	 
	 TwoDMatrix(int=5,int=5);    //member function   //overload constructer //default values
	~TwoDMatrix();				//destructor
	 void display()const;		//display matrix
	 TwoDMatrix(const  TwoDMatrix& );	 //copy constructor
	int getrow()const;		//get # of rows
	 int getclm()const;		//get # of column
	 const TwoDMatrix& operator= (const TwoDMatrix& );//overloading assignment operator 
	
	 int &TwoDMatrix::operator()(const int ,const int );//overloading function call operator for retrieve nd changena value



	 void operator !();// overload ! for tranpose
	 TwoDMatrix operator +(const TwoDMatrix&  );// overload + for addition
	 
	 TwoDMatrix& operator *=(int );// overload * for multiply by integer
	 TwoDMatrix operator *(const TwoDMatrix&  );// overload *= for  multiply 
	 

	 
friend ostream& operator <<(ostream& out,const TwoDMatrix&);//overloading exersion operator
friend istream& operator >>(istream& in, TwoDMatrix&); //overloading insersion operator
friend ifstream& operator >>(ifstream& in, TwoDMatrix&); //overloading insersion operator

};
#endif;



