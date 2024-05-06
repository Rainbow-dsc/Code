#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int g=a%10,j=b%10;
	int d=g*10+j,q=j*10+g;
	cout<<(d>q?d:q)<<endl;	
	return 0;
}

