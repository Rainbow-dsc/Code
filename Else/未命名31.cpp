#include<iostream>
using namespace std;
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9},n;
	cin>>n;
	for(int i=0;i<9;i++)
	{
		if(n!=a[i])
		{
			cout<<a[i]<<" ";
		}
	}
	return 0;
}

