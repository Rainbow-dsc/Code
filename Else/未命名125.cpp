#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	int n;
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{	
	if(a[i]!=' ')
	{
		cout<<a[i];
	}
	}

	return 0;
}


