#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
using namespace std;
int sum1=0,sum2=0,sum3=0;
string a;  
int main()
{
	getline(cin,a);
	int len1=a.size();
	for(int i=0;i<len1;i++)
	{
		if(a[i]==32)
		{
			sum1=sum1+1;
		} 
		else if(48<=a[i]&&a[i]<=57)//a-z£º97-122 A-Z£º65-90 0-9£º48-57 
		{
			sum2=sum2+1;
		}
		else if(65<=a[i]&&a[i]<=122)
		{
			sum3=sum3+1;
		}
	} 
	cout<<"letters:"<<sum3<<' '<<"space:"<<sum1<<' '<<"digit:"<<sum2; 
	return 0;
}


