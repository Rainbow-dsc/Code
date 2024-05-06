#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	int u=0,p,a[1000];
	cin>>p;
	for(int i=0;i<p;i++)
	{
		cin>>a[i];
	} 
	for(int i=0;i<p;i++) 
	{
		u=u+a[i];
	}
	cout<<u; 
	return 0;
}


