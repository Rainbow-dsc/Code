#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int max=(a>b?a:b)>c?(a>b?a:b):c;
	int min=(a<b?a:b)<c?(a<b?a:b):c;
	int d=a+b+c-max-min;
	cout<<d; 
	return 0;
}


