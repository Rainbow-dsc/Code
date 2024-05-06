#include<iostream>
#include<iomanip>
using namespace std; 
int main()
{
	float x;
	cin>>x;
	if(x<0.5)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<(x>1-2*x?1-2*x:x)<<endl;
	}
	else
	{
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<(1-x>2*x-1?2*x-1:1-x)<<endl;
	}
	return 0;
}

