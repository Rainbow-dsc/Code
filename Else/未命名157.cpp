#include<iostream>
using namespace std;
int Sum(int a,int b,int c) 
{
	int d=a>b?a:b;
	int e=d>c?d:c;
	int f=a<b?b:a;
	int g=f<c?f:c;
	return e-g;
}
int main()
{
	int a,b,c 
	cin>>a>>b>>c;
	cout<<Sum(a,b,c);
	return 0;
}


