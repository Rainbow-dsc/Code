#include<iostream>
#include<iomanip>
using namespace std;
float a,b,c,s; 
int main()
{
	cin>>a>>b;
	c=2*(a+b);
	s=a*b;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<c<<endl<<s<<endl;
	return 0;
}

