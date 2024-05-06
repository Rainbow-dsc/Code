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
	int s,i=0;
	cin>>s;
	if(s==0||s==1)
	{
		cout<<2;
		return 0;
	}
	while(1)
	{
		if(poi(s)==1)
		{
			cout<<s;
			return 0;
		} 
		if(poi(s+i))
		{
			cout<<s+i;
			return 0;
		} 
		else if(poi(s-i))
		{
			cout<<s-i;
			return 0;
		}
		i++;
	} 
	return 0;
}


