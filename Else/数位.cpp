#include<iostream>
using namespace std;
int main()
{
	int a; 
	cin>>a;
	if(0<=a && a<10)
		cout<<"1";
	else if(10<=a && a<100)	
		cout<<"2";
	else
		cout<<"3";
	return 0;
}

