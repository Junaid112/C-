// BSEF11M026
// JUNAID AHMED GHAURI

#include<iostream>   //input file stream
#include"TwoDMatrix.h" //include heaer file of TwoDMatrix
#include<cstring>
#include<fstream>
using namespace std;

TwoDMatrix::TwoDMatrix(int r,int c) //overload constructer 
{
	nr=r;
	nc=c;
	ptr=new int *[r];
	for(int i=0;i<r;i++)
	{
		ptr[i]=new int[c];
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			ptr[i][j]=0;
		}
	}

}

TwoDMatrix::~TwoDMatrix()	//destructor
{
	for(int i=0;i<nr;i++)
	{
		delete []ptr[i];
		ptr[i]=0;
	}
	delete [] *ptr;
	ptr=0;
}


void TwoDMatrix::display()const	//display matrix
{
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			cout<<ptr[i][j]<<" ";
		}
		cout<<endl;
	}
}

 TwoDMatrix:: TwoDMatrix(const  TwoDMatrix& m )	 //copy constructor
 {
	nr=m.nr;
	nc=m.nc;
	
	ptr=new int *[nr];
	for(int i=0;i<nr;i++)
	{
		ptr[i]=new int[nc];
	}
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			ptr[i][j]=m.ptr[i][j];
		}
	}

}

 int TwoDMatrix::getrow()const  //get # of rows
 {
	 return nr;
 }

 int TwoDMatrix::getclm()const  //get # of column
 {
	 return nc;
 }

 const TwoDMatrix& TwoDMatrix::operator= (const TwoDMatrix& m)  //oveerloading assignment operator 
{
	nr=m.nr;
	nc=m.nc;
	if(ptr!=0)
	{
		for(int i=0;i<nr;i++)
	{
		delete []ptr[i];
		ptr[i]=0;
	}
	delete [] *ptr;
	ptr=0;

	}
	ptr=new int *[nr];
	for(int i=0;i<nr;i++)
	{
		ptr[i]=new int[nc];
	}
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			ptr[i][j]=m.ptr[i][j];
		}
	}

	
	return *this;
}



void TwoDMatrix::operator !()// overload ! for tranpose
{
	
	TwoDMatrix temp(nc,nr);
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			temp.ptr[j][i]=ptr[i][j];
		}
	}
	
	for(int i=0;i<nr;i++)
	{
		delete []ptr[i];
		ptr[i]=0;
	}
	delete [] *ptr;
	ptr=0;
	nc=0;
	nr=0;
	nr=temp.nr;
	nc=temp.nc;
	ptr=new int *[nr];
	for(int i=0;i<nr;i++)
	{
		ptr[i]=new int[nc];
	}
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			ptr[i][j]=temp.ptr[i][j];
		}
	}
	
	
}

 TwoDMatrix  TwoDMatrix::operator +(const TwoDMatrix& m)// overload + for addition
 {

	 if(nr!=m.nr || nc!=m.nc)
	 {
		 cout<<endl;
		 exit(1);
	 }
	 else
	 {
		 
		 TwoDMatrix temp(nr,nc);
		 for(int i=0;i<nr;i++)
		{
		for(int j=0;j<nc;j++)
			{
				temp.ptr[i][j]=ptr[i][j]+m.ptr[i][j];
			}
		}
		 return temp;
		 
		 
	 }
	 
 }


 TwoDMatrix& TwoDMatrix::operator *=(int n)// overload *= for multiply by integer
 {
	 for(int i=0;i<nr;i++)
		{
		for(int j=0;j<nc;j++)
			{
				ptr[i][j]=ptr[i][j]*n;
			}
		}
	 return *this;
 }

TwoDMatrix TwoDMatrix::operator *(const TwoDMatrix& m )// overload *= for  multiply

 {
	 
	 if(nr!=m.nc || nc!=m.nr)
	 {
		
		  
		 cout<<endl;
		 exit(1);
	 }
	 else
	 {
		 
		 TwoDMatrix temp(nr,m.nc);
		 for(int i=0;i<temp.nr;i++)
		{
		
				
				for(int adr=0;adr<nr;adr++)
				{ 
					int s=0;
					for(int k=0;k<nc;k++)
					{
						s=s+(ptr[adr][k]*m.ptr[k][i]);
					}
					temp.ptr[adr][i]=s;
				}
			
		}
		 return temp;
		 
		 
	 }
 }



int &TwoDMatrix::operator()(const int r,const int c) //overloading function call operator for retrieve a value
{

return ptr[r][c];

}