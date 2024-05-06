#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float c[100];
	int f;
	cin>>f;
	for(int n=0;n<f;n++) 
	{
		cin>>c[n];
		c[n]=5*(c[n]-32)/9;
	}
	for(int n=0;n<f;n++)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<c[n]<<" ";
	}
	return 0;
}

