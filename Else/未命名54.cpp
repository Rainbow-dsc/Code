#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int f;
	float c;
	cin>>f;
	c=5*(f-32)/9;
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<c;
	return 0;
}

