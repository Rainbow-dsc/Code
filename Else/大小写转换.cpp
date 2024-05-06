#include<iostream>
using namespace std;
int main()
{
	char c;
	cin>>c;
	if(c>='A'&&c<='Z')
	{
		cout<<(char)(c+32)<<endl;
	}
	else
	{
		cout<<c;
	}
	return 0;
}

