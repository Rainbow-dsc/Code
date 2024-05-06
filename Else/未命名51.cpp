#include<iostream>
using namespace std;
int main()
{
	int a,b[100],d=0;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<a;i++)
	{
		d=d+b[i];	
	}
	cout<<d;
	cout<<endl;
	cout<<b[2]; 
	return 0;
}

