#include<iostream>
using namespace std;
int score;
int main()
{
	cin>>score; 
	if(score>=85)
	{
		cout<<"excellent"<<endl;
	}
	else if(score<60)
	{
		cout<<"fail"<<endl;
	}
	return 0;
}

