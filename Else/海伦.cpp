#include<iostream>
#include<cmath>
#include<iomanip> 
using namespace std;
float a,b,c,p,s;
int main()
{
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt((p*(p-a)*(p-b)*(p-c)));
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<s<<endl;
	return 0;
}

