#include<iostream>
using namespace std;
int a,b,c; 
int main()
{
	cin>>a>>b;
	c=(a%2==b%2)?a*b:a+b;
	cout<<c;
	return 0;
}

