#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;
int main()
{
	int a,b;
	srand(time(NULL));
	a=rand()%100+1;
	cout<<"傻子，请输入一个数:\n";
	cin>>b;
	while(b!=a)
	{ 
	if(b>a)
	{
		cout<<"傻子，猜大了，请重新猜:\n";
		cin>>b;
	}
	else
	{
		cout<<"傻子，猜小了，请重新猜:\n";
		cin>>b;
	}
	}
	cout<<"傻子，恭喜你，猜对了，中奖56亿\n";
	
	return 0;
}
