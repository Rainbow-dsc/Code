#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a[10],S,v;
	int c=0;
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
		S=S+a[i];
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<S/10<<endl; 
	v=S/10;
	for(int p=0;p<10;p++)
	{
		 if(a[p]>v)
		 	c++;
	} 
	cout<<c;
	return 0;
}
