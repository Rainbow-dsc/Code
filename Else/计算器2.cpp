#include<iostream>
using namespace std;
int main()
{
	double a,b;
	char c;
	cin>>a>>c>>b;
	switch (c)
	{
		case '+':cout<<a+b<<endl;break;
		case '-':cout<<a-b<<endl;break;
		case '*':cout<<a*b<<endl;break;
		case '/':cout<<a/b<<endl;break;
		default :cout<<"��������";break; 
	}
	return 0;
}

