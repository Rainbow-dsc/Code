#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main()
{
	char a[100]; 
	int sum=0;
	cin>>a;
	int  len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]==97||101||105||111||117)
		{
			sum=sum+1;
		}	
	}
	cout<<sum;
	return 0;
}


