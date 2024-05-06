#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a,b;
	cin>>a>>b;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<a-b<<endl;
	return 0;
}
 
