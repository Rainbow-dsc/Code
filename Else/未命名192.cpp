#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%100!=0&&a%4==0||a%400==0)
	{
		cout<<"leap year";
	} 
	else 
	{
		cout<<"common year";
	}
	return 0;
}


