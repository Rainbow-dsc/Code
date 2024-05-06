#include<iostream>
using namespace std;
int main()
{
	int a[3][3],k;
	for(int i=0;i<3;i++)
	{
		for(int o=0;o<3;o++)
		{
			cin>>a[i][o];
		}
	}
	k=a[0][0]+a[1][1]+a[2][2]+a[0][2]+a[2][0];
	cout<<k;
	return 0;
}

