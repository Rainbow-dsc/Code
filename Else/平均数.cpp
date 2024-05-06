#include<iostream>
#include<iomanip> 
using namespace std;
float a,b,c; 
int main()
{
	cin>>a>>b>>c;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<(a+b+c)/3;
	return 0;
}

