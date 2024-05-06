#include<iostream>
using namespace std;
int dsc(int a)
{
	for(int i=2;i<a;i++)
		if(a%i==0) return 0;
	return 1;
}
int as(int a)
{
	int sum=0,n=a;
	while(n!=0)
	{
		sum=sum*10+n%10;
		n=n/10;
	}
	if(sum==a) return 1;
}
int main()
{
	for(int i=2;i<1000;i++)
	{
		if(dsc(i)==1&&as(i)==1)cout<<i<<' '; 
	}
	return 0;
}
	

