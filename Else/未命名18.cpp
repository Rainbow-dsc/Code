#include<iostream>
using namespace std;
int main()
{
	int n,a=0;
	cin>>n;
	for(;n>0;n/=10)
	{
		a=n%10;
		cout<<a;
	}
	return 0; 
}

