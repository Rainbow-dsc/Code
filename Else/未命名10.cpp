#include<iostream>
#include<windows.h>
#include<time.h> 
using namespace std;
int main()
{
	int n,i;
	srand(time(NULL));//������������� 
	n=rand()%30+1;//��������� 
	cout<<"ɵ�ӣ����������Ĳ�Ʊ���룺\n"; 
	cin>>i; 
	while(i!=n)
	{
		cout<<"ɵ�ӣ���û���н��������¹���\n";
		cin>>i;
	} 
	cout<<"��ϲ�㣬ɵ������5000�򣡣���"; 
	return 0;
}

