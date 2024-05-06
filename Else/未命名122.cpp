#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n=0;
	char a[100];
	gets(a);
	n=strlen(a);
	for(int j=n-1;j>=0;j--)
	{
		cout<<a[j];
	}
	return 0;
}


