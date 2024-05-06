#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
float h,g=9.8,t;
int main()
{
	cin>>h;
//	h=(1/2)*g*t*t;
	t=sqrt(2*h/g);
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<t<<"s";
	return 0;
}
