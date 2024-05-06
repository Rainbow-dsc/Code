#include<iostream>
using namespace std;
int main()
{
	int a,c,d,b;
	cin>>a>>b>>c;
	if(a+b+c==180&&a<90&&b<90&&c<90)
	{
		cout<<"acute triangle";
	}
	else if(a==90||b==90||c==90)
	{
		cout<<"right triangle";
	}
	else if(a>90||b>90||c>90)
	{
		cout<<"obtuse triangle";
	}
	return 0;
}

