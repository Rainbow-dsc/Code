#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1000],b;
	gets(a);
	cin>>b;
	int sum=0;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]==b)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}


