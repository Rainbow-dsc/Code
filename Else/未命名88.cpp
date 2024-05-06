#include <iostream>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if(a-b>0)
	{
		cout<<a-b;
	}
	else if(a-b<0)
	{
		cout<<b-a<<endl;
	}
	return 0;
}
