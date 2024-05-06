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
	for(int i=2;i<20;i++)
	{
		if(poi(i)==1)
			if(poi(pow(2,i)-1)==1)
			{
				cout<<pow(2,i)-1<<endl;
			}
	}
	return 0;
}
