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
	for(int i=11;i<s;i++)
	{
		if(poi(i)==1)
		{
			
		}
	} 
	return 0;
}
