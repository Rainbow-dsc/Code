#include<iostream>
using namespace std;
int main()
{
	int score;
	cin>>score;
	if(score>=90)
	{
		cout<<"A";
	}
	else if(score>=80&&90>score)
	{
		cout<<"B";
	}
	else if(score>=70&&80>score) 
	{
		cout<<"C";
	}
	else if(score>=60&&70>score)
	{
		cout<<"D";
	}
	else if(60>=score) 
	{
		cout<<"E";
	}
	return 0;
}


