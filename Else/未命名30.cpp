#include<iostream>
using namespace std;
int main()
{
	int a[100],n,m=0; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(m<a[i])
		{
			m=a[i];
		}
	}
		cout<<m;
	return 0;
}

