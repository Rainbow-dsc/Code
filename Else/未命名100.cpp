#include<iostream>
using namespace std;
int main()
{
	int a[1000];
	int b;
	cin>>b;
	int SUM=0;
	for(int i=0;i<b;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<b;i++)
	{
		SUM=SUM+a[i];
	}
	cout<<SUM;
	return 0;
}

