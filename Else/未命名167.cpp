#include<iostream> 
#include<cstring>
#include<stdio.h>
using namespace std;
int sum=0,dsc=0;
char a[60];
int main()
{
	gets(a); 
	int b;
	b=strlen(a);
	for(int i=0;i<b;i++)
	{
		if(a[i]!='O') 
		{
			dsc=0;
			
		}
		else
		{
			dsc++;
			sum=sum+dsc;
		}
	} 
	cout<<sum;
	return 0;
}
