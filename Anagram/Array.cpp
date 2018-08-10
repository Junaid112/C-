#include<iostream>
#include"Array.h"
#include<stdexcept>
using namespace std;


Array ::Array(int i)
{
	if(i<=0)
	{
		size=0;
		data=0;
		return;
	}
	else
	{
		size=i;
		data=new char[size];
	}
}

Array :: Array(const Array & orig)
{
	size=orig.size;
	if(size==0)
	{
		data=0;
		return;
	}
	data=new char[size];
	for(int c=0;c<size;c++)
	{
		data[c]=orig.data[c];
	}
}
Array & Array :: operator = (const Array & rhs)
{
	if(this==&rhs)
	{
		return *this;
	}
		if(rhs.size==0)
	{
		size=rhs.size;
		data=0;
		return *this;
	}
	size=rhs.size;
	data=new char[size];
	for(int c=0;c<size;c++)
	{
		data[c]=rhs.data[c];
	}
}
int  Array ::isValidIndex(int i)
{
	return (i>=0 && i<=size-1); 
}
char & Array :: operator [] (int i)
{
	if(isValidIndex(i))
	{
		return data[i];
	}
	else
	{
		throw exception("\n\n *Index out of range...! ");
	}

}
void Array :: reSize(int s)
{
	
	if(size+s<=0)
	{
		size=0;
		delete [] data;
		data=0;
	}
	else
	{
		char *temp;
		temp=new char[size+s];
		if(s>=0)
		{
			for(int c=0;c<size;c++)
				temp[c]=data[c];
			delete [] data;
			data=temp;
			size=size+s;
		}
		else
		{
			for(int c=0;c<size+s;c++)
				temp[c]=data[c];
			delete [] data;
			data=temp;
			size=size+s;
		}
	}

}

void Array ::removeChar(char a)
{
	int chek=0;
	//char *temp=new char[this->size];
	for(int i=0;i<this->getNoOfCharWithSpace();i++)
	{
		if(data[i]==a)
		{
			chek=i;
		}
	}
	data[chek]=data[this->getNoOfCharWithSpace()-1];
	data[this->getNoOfCharWithSpace()-1]='\0';
	/*for(int i=0;i<this->getNoOfChar()+1;i++)
	{
		if(i!=chek && f==0)
		{
			temp[i]=data[i];
		}
		else
		{
			temp[i]=data[i+1];
			if(temp[i]=='\0')
			break;
			f++;
		}
	}*/
	/*for(int i=0;i<size;i++)
	{
		if(this->data[i]!=a || chek>0)
			temp[i]=this->data[i];
		else
			chek++;

		if(temp[i]=='\0')
			break;
	}*/
	/*delete [] this->data;
	this->data=temp;
	temp=0;
	this->size=this->size-1;*/

}
bool Array ::ismember (char a )
{
	for(int i=0;i<data[i]!='\0';i++)
	{
		if(this->data[i]==a)
			return 1;
	}
	return 0;
}
bool Array ::isAnagram(Array& sub)
{
	bool flag=1;
	Array temp;
	temp=*this;
	if(temp.getNoOfChar()==sub.getNoOfChar())
	{
		for(int i=0;i<sub.getNoOfChar() && flag==1;i++)
		{
			if(sub.data[i]!=' ')
			{
				if(temp.ismember(sub.data[i]))
					{
						flag=1;
						temp.removeChar(sub.data[i]);
					}
					else
						return 0;
				
			}
		}
		return flag;
	}
	else
		return 0;
	
}
int Array ::getNoOfChar()const
{
	int c=0;
	for(int i=0;i<size && data[i]!='\0';i++)
		{
			if(data[i]!=' ')
			c=c+1;
		}
	return c;
}

int Array ::getNoOfCharWithSpace()const
{
	int c=0;
	for(int i=0;i<size && data[i]!='\0';i++)
		{
			
			c=c+1;
		}
	return c;
}
Array ::~Array()
{
	if(data)
	{
		delete [] data;
		data=0;
	}
	size=0;
}
	



