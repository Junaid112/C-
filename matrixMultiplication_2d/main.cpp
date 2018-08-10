// BSEF11M026
// JUNAID AHMED GHAURI

#include<iostream>						//input file stream
#include"TwoDMatrix.h"				//include heaer file of TwoDMatrix
#include<cstring>
#include<fstream>
using namespace std;

int main()//driver function
{
	ifstream input;
	input.open("input.txt");//open txt file
	if(!input)//file open validation
	{
		cout<<"\n *** Input file not found...! \n";
	}
	else
	{
	int nMatrix=0,choice=0;
	input>>nMatrix;
	TwoDMatrix *matrix;
	matrix=new TwoDMatrix[nMatrix];    // dynamic array of matrixes
	int row=0,column=0;
	for(int i=0; i<nMatrix;i++)        //reading from file
	{
		input>>row;
		input>>column;
		TwoDMatrix m(row,column);
		input>>m;	
		matrix[i]=m;
		
		
	}
	 
	do									// display MENU and operate functions
	{
		cout<<"\n\nReading data from ""input.txt""...\n"; 
		cout<<endl;
		cout<<"File opened successfully and "<<nMatrix<<" matrices have been read\n"; 
		cout<<endl;
		cout<<"Menu \n1. Display a matrix\n"; 
		cout<<"2. Display ALL matrices \n";
		cout<<"3. Modify an element in a matrix\n"; 
		cout<<"4. Modify a whole matrix \n";
		cout<<"5. Take transpose of a matrix\n"; 
		cout<<"6. Add two matrices \n";
		cout<<"7. Multiply two matrices\n"; 
		cout<<"8. Multiply a matrix with an integer \n";
		cout<<"9. Quit \n";
 
		cout<<"\nEnter your choice: ";
		
		cin>>choice;
		while(choice <0 || choice >9)
		{
			

		cout<<endl;
			cout<<"\n *** Error selec given choice...! \n";
			cout<<"\nEnter your choice Again : ";
			cin>>choice;
		}
		switch(choice)				// switch for choice
		{
			case 1:					//choice # 1
			{
				int n=0;
				cout<<"\n**Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n;
				while(n<0 || n>nMatrix-1)
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n;

				}
				cout<<endl;
				cout<<"**The matrix is :\n\n";
				cout<<matrix[n];
				cout<<endl;
				cout<<endl;
			}
			break;
			case 2:					//choice # 2
			{
				cout<<"\nYou selected \n\n2. Display ALL matrices \n";
				for(int i=0;i<nMatrix;i++)
				{
					
					cout<<"Matrix # "<<i;
					cout<<endl;
					cout<<endl;
					cout<<matrix[i];
					cout<<endl;
					cout<<endl;

				}
			}
			break;
			case 3:				//choice # 3
			{
				cout<<"\nYou selected \n\n3. Modify an element in a matrix\n";
				
				int n=0;
				
				do
				{
					if(n<0 || n>nMatrix-1)
					{cout<<"\n**invalid input Enter in range ..!\n";
					}
					cout<<"\n**Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n;
					if(n>=0 && n<=nMatrix-1)
					{
						int n1=0,n2=0,v=0;
						cout<<"\n Enter row # :";
						cin>>n1;
						while(n1<0 || n1>matrix[n].getrow())
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter row number of your choice *(0--"<<matrix[n].getrow()-1<<"): ";
				cin>>n1;

				}
						cout<<"\n Enter column # :";
						cin>>n2;
								while(n2<0 || n2>matrix[n].getclm())
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter column number of your choice *(0--"<<matrix[n].getclm()-1<<"): ";
				cin>>n2;

				}
						cout<<endl;
						cout<<"\n Before modifying The element is :";
						cout<<matrix[n](n1,n2);
						cout<<"\n Enter value want to replace with this value :";
						cin>>matrix[n](n1,n2);
						cout<<"\n After modifying The element is :";
						cout<<matrix[n](n1,n2);
						cout<<endl;
					}
				}
				while(n<0 || n>nMatrix-1);

				
				
			}
			break;
			case 4:					//choice # 4
			{
				int n=0;
				cout<<"\nYou selected \n\n4. Modify a whole matrix \n";
				cout<<"\nwhich Matrix # want to modify: ";
				cin>>n;
				while(n<0 || n>nMatrix-1)
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n;

				}
				cin>>matrix[n];
				cout<<"\n After modify matrix is :\n";
				cout<<matrix[n];
				cout<<endl;

			}
			break;
			case 5:					//choice # 5
			{
				
				cout<<"\nYou selected \n\n5. Take transpose of a matrix\n"; 
				int n=0;
				cout<<"\nwhich Matrix # want to Transpose: ";
				cin>>n;
				while(n<0 || n>nMatrix-1)
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n;

				}
				!matrix[n];
				cout<<matrix[n];
			
			}
			break;
			case 6:					//choice # 6
			{
				cout<<"\nYou selected \n\n6. Add two matrices \n";
				int n1=0,n2=0;
					cout<<"\nwhich Matrix # want to add: ";
					cin>>n1;
					cout<<"\nwhich Matrix # want to add with: ";
					cin>>n2;
				while(matrix[n1].getrow()!=matrix[n2].getrow() || matrix[n1].getclm()!=matrix[n2].getclm())
				{
					 cout<<"\nERROR..! (Not equal number of rows or column ) *** Enter again\n";
					cout<<"\nwhich Matrix # want to add: ";
					cin>>n1;
					cout<<"\nwhich Matrix # want to add with: ";
					cin>>n2;
					
				}
				
				cout<<matrix[n1]+matrix[n2];
			}
			break;
			case 7:				//choice # 7
			{
				cout<<"\nYou selected \n\n7. Multiply two matrices\n";
				int n1=0,n2=0;
				cout<<"\nwhich Matrix # want to Multiply: ";
				cin>>n1;
				cout<<"\nwhich Matrix # want to Multiply with: ";
				cin>>n2;
				while(matrix[n1].getclm()!=matrix[n2].getrow())
				{
					cout<<"\nERROR..! (Not equal number of column of 1st matrix and rows of 2nd )..!\n *** Enter Again";
					cout<<"\nwhich Matrix # want to Multiply: ";
					cin>>n1;
					cout<<"\nwhich Matrix # want to Multiply with: ";
					cin>>n2;
				}
				cout<<matrix[n1]*matrix[n2];
			}
			break;
			case 8:				//choice # 9
			{
				cout<<"\nYou selected \n\n8. Multiply a matrix with an integer \n";
				int n1=0,n2=0;
				cout<<"\nwhich Matrix # want to Multiply: ";
				cin>>n1;
				while(n1<0 || n1>nMatrix-1)
				{
					cout<<"\n** ! Enter Witnin limit ***\n * Again Enter Matrix number of your choice *(0--"<<nMatrix-1<<"): ";
				cin>>n1;

				}
				cout<<"\nEnter number want to Multiply with: ";
				cin>>n2;
				
				matrix[n1]*=n2;
				cout<<matrix[n1];
			}
			break;
			
		}
		
	}
	while(choice!=9);
	cout<<"\nYou selected \n\n9. Quit \n"; 
	cout<<"\n *** Program Has been Terminated ***\n";
	}
	
	return 0;
}


ostream& operator <<(ostream& out,const TwoDMatrix &s)   //overloading exersion operator
{
	s.display();

	return out;
}
istream& operator >>(istream& in, TwoDMatrix&m)   //overloading insersion operator
{
	
	
	cout<<"\n This matrix has "<<m.nr<<" rows & "<<m.nc<<"columns";
	for(int i=0;i<m.nr;i++)
	{
		cout<<"\nEnter elements of row # "<<i<<"  *Only * "<<m.nc<<" Elements are accepted "<<endl;
		
		for(int j=0;j<m.nc;j++)
		{
			in>>m.ptr[i][j];
		}
		
	}

	
	return in;
}

ifstream& operator >>(ifstream& fin, TwoDMatrix&m)   //overloading insersion operator
{
	for(int i=0;i<m.nr;i++)
	{
		for(int j=0;j<m.nc;j++)
		{
			fin>>m.ptr[i][j];
		}
		
	}
	
	return fin;
}
