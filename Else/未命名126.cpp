#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	int o=0;
	gets(a);
	o=strlen(a);
	for(int i=0;i<o;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			char(a[i]+=32);
		}
	} 
	cout<<a;
	return 0;
}


