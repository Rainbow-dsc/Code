#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,c=0;
	float b=1.3,d,a[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>d;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=b+d)
		{
			c++;
		}
	}
	cout<<c; 
	return 0;
}
