#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	float a[100];
	cin>>n;
	float s;
	float g;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<n-1;i++)
	{
		s+=a[i];	
	} 
	g=s/(n-2);
	float max=a[n-2]-g;
		float min=g-a[1];
		float m=max>min?max:min;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<g<<' '; 
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<m<<' ';	
	return 0;
}




