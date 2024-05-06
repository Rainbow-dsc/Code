#include<bits/stdc++.h>
using namespace std;
int poi(int a)
{
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
		{
			return 0;
		} 
	}
	return 1;
} 
int main()
{
	int s;
	cin>>s; 
	if(s==1||s==0)
	{
		cout<<"no";
		return 0; 
	} 
	if(poi(s)==1)
	{
		cout<<"yes";
	} 
	else
	{
		cout<<"no";
	}
	return 0;
}
