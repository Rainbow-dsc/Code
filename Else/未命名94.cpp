#include <iostream>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if ((a+b)%2==0)
	{
		cout<<"even"<<endl;
	}
	else if((a+b)%2!=0)
	{
		cout<<"odd"<<endl;
	}
	return 0;
}
