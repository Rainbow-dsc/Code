#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100],b[0];
	int o=0;
	gets(b);
	for(int i=0;i<o;i++)
	{
		cin>>a[i];
	}
	o=strlen(a);
	for(int i=0;i<o;i++)
	{
		if(a[i]!=b[0])
		{
			cout<<a[i];
		}
	} 
	return 0;
}
