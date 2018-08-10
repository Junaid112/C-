

#include<iostream>
#include<stdexcept>
#include<cstring>
#include<fstream>
#include"Array.h"
using namespace std;

int findSizeWithSpace(char* );
char firstNonRepeat(char* );
int findSize(char*);
bool isAnagram(char*,char*);
int main()
{
	cout<<"first non repeating alphabet is: "<<firstNonRepeat("peerpan")<<endl;
	int n;
	ifstream read;
	read.open("input.txt");
	if(read)
	{
		cout<<"\n ** File has successfully read.....!\n";

		read>>n;
		read.ignore();
	
		char **ptr=new char*[n];

		for(int i=0;i<n;i++)
		{
			ptr[i]=new char[20];
			read.getline(ptr[i],20,'\n');
		
		}

		for(int i=0;i<n;i++)
		{
		
			for(int j=i+1;j<n;j++)
			{
				if(isAnagram(ptr[i],ptr[j]))
					cout<<"\n "<<ptr[i]<<" = "<<ptr[j];
			}
		}

	}
	else
		cout<<"\n ** File is not fount.....!\n";			
	return 0;
}
int findSize(char* ary)
{
	int count=0;
	for(int i=0;ary[i]!='\0';i++)
	{
		if(!(ary[i]==' '))
			{
				count++;
			}
	}
	return count;
}
int findSizeWithSpace(char* ary)
{
	int count=0;
	for(int i=0;ary[i]!='\0';i++)
	{
		count++;
	}
	return count;
}
//
//bool isAnagram(char* a,char* b)
//{
//	if((findSize(a))!=(findSize(b)))
//	{
//		return 0;
//	}
//	else
//	{
//		int count=0;
//			for(int i=0,j=0; a[i]!='\0' ;)
//			{
//				if(a[i]==' ')
//				{
//					i++;
//				}
//
//				else
//				{
//
//					if(a[i]==b[j])
//					{
//						count++;
//						i++;
//						j=0;
//					}
//					else if(b[j]=='\0')
//					{
//						i++;
//						j=0;
//					}
//					else
//						j++;
//				}
//			}
//			if(count==findSize(a))
//				return 1;
//			else
//				return 0;
//	}
//}
	


bool isAnagram(char* a,char* b)
{
	if((findSize(a))!=(findSize(b)))
	{
		return 0;
	}
	else
	{
		int alfaFrequency[26];
		for(int i=0;i<26;i++)
		{
			alfaFrequency[i]=0;
		}

		for(int i=0;a[i]!='\0';i++)
		{
			++alfaFrequency[(int)a[i]-97];
		}

		for(int i=0;a[i]!='\0';i++)
		{
			--alfaFrequency[(int)a[i]-97];
		}

		for(int i=0;i<26;i++)
		{
			if(alfaFrequency[i]!=0)
				return 0;
		}

		return 1;
	}
}



//char firstNonRepeat(char* a)
//{
//	
//		int j=findSizeWithSpace(a)-1;
//		int i;
//			for( i=0;  i!=j && a[i]!=a[j] ;)
//			{
//				if(a[i]==a[j])
//				{
//					i++;
//				}
//				else
//				{
//					j--;
//				}
//
//			}
//			if(j>0)
//			return a[j-1];
//			return a[j];
//			
//}

char firstNonRepeat(char* a)
{
	int alfaFrequency[26];
		for(int i=0;i<26;i++)
		{
			alfaFrequency[i]=0;
		}

		for(int i=0;a[i]!='\0';i++)
		{
			++alfaFrequency[(int)a[i]-97];
		}

		for(int i=0;a[i]!='\0';i++)
		{
			if(alfaFrequency[(int)a[i]-97]==1)
				return a[i];
		}
			
}


//ostream& operator <<(ostream& out,const Array &);
//istream& operator >>(istream& in, Array&);
//ifstream& operator >>(ifstream& in, Array&);
//
//int main()
//{
//
//	/*Array a1,a2;
//	cin>>a1;
//	cin>>a2;
//	
//	if(a1.isAnagram(a2))
//		cout<<a1<<a2;*/
///
//	int n;
//	ifstream read;
//	read.open("input.txt");
//	if(read)
//	{
//		cout<<"\n ** File has successfully read.....!\n";
//
//		read>>n;
//		read.ignore();
//	
//		Array *ptr=new Array[n];
//		for(int i=0;i<n;i++)
//		{
//			read>>ptr[i];
//		
//		}
//
//		for(int i=0;i<n;i++)
//		{
//		
//			for(int j=i+1;j<n;j++)
//			{
//				if(ptr[i].isAnagram(ptr[j]))
//					cout<<"\n "<<ptr[i]<<" = "<<ptr[j];
//			}
//		}
//
//	}
//	else
//		cout<<"\n ** File is not fount.....!\n";
//*/
//	return 0;
//}
//
//ostream& operator <<(ostream& out,const Array &s)
//{
//	for(int i=0;i<s.size && s.data[i]!='\0';i++)
//	{
//		out<<s.data[i];
//	}
//
//	return out;
//}
//istream& operator >>(istream& in, Array&s)
//{
//
//	Array temp(s.size+1);
//	in.getline(temp.data,temp.size);
//	s=temp;
//	return in;
//}
//ifstream& operator >>(ifstream& inf, Array& s)
//{
//
//	Array temp(s.size+1);
//	inf.getline(temp.data,temp.size);
//	s=temp;
//	return inf;
//}
