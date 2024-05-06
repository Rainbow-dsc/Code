#include<iostream>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if(a>0 || b>0)
		cout<<"yes";
	if(a<=0&&b<=0)
		cout<<"no";
	return 0;
}

