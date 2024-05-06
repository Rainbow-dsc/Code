#include<iostream>
#include<cstring>
#include<stdio.h> 
using namespace std;
int main()
{
	char a[1000];
	int SUM=0,c=0;
	cin>>a;
	int b=strlen(a);
	for(int i=0;i<b;i++)
	{
		SUM=0; 
		if(a[i]>='0'&&a[i]<='9')
		{
			while(a[i]>='0'&&a[i]<='9')
			{
				SUM=SUM*10+a[i]-'0';
				i++;	
			}
			c=SUM+c;
		}
	}
	cout<<c;
	return 0;
}

