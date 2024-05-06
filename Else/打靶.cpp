#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int a,b;
	b=(x-y+240)/64;
	a=b+y/32;
	cout<<a<<endl<<b;	 
	return 0;
}

