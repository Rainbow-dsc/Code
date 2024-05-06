#include<iostream>
using namespace std;
int main()
{
	int n,s=0,b;
	cin>>n;
	for(int a=0;a<n;a++)
	{
		cin>>b;
		s=s+b;
	}
	cout<<s;
	return 0; 
}

