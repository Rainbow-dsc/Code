#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,c;
	float a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[1]>a[i-1])
	{
		c=a[1]-a[i-1];
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<c;
	} 
	else
	{
		c=a[i-1]-a[1];
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<c;
	}
	}
	
	return 0;
}

