#include<iostream>
using namespace std;
int a;
int main()
{
	cin>>a;
	if((a%4==0 && a%100!=0)||a%400==0)
	{
		cout<<"ÈòÄê";
	}
	else
	{
		cout<<"Æ½Äê"; 
	}
	return 0;
}

