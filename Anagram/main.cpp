#include<iostream>
using namespace std;
int findSize(char*);
int isAnagram(char*,char*);
int main()
{
	int check=0;
	char data1 []={"ok i now donut"};
	char data2 []={"i do not know u "};


		check=isAnagram(data1,data2);
	
		if(check==findSize(data2))
		{	
			cout<<"these are anagrams\n";
		}
		else
			cout<<"these are not anagrams";
		return 0;
	
			
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
int isAnagram(char* a,char* b)
{
	if((findSize(a))!=(findSize(b)))
	{
		cout<<"The arrays are not anagrams";
	}
	else
	{
		int count=0;
			for(int i=0,j=0; a[i]!='\0' ;)
			{
				if(a[i]==' ')
				{
					i++;
				}

				else
				{

					if(a[i]==b[j])
					{
						count++;
						i++;
						j=0;
					}
					else if(b[j]=='\0')
					{
						i++;
						j=0;
					}
					else
						j++;
				}
			}
			return count;
	}
}
	
