#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;
int main()
{
	int a,b;
	srand(time(NULL));
	a=rand()%100+1;
	cout<<"ɵ�ӣ�������һ����:\n";
	cin>>b;
	while(b!=a)
	{ 
	if(b>a)
	{
		cout<<"ɵ�ӣ��´��ˣ������²�:\n";
		cin>>b;
	}
	else
	{
		cout<<"ɵ�ӣ���С�ˣ������²�:\n";
		cin>>b;
	}
	}
	cout<<"ɵ�ӣ���ϲ�㣬�¶��ˣ��н�56��\n";
	
	return 0;
}
