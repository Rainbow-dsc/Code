#include<iostream>
using namespace std;
int main()
{
	int m[54],n,d=54;
	cin>>d;
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
		if(m[0]==m[i-1])
		{
			cout<<"YES";
		} 
	}
	cout<<"NO";
	return 0;
}

