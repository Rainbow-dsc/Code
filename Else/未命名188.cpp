#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	int a,b,c,s;
}f[1125];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>f[i].a>>f[i].b ;
		f[i].c=(f[i].a +f[i].b )*2;
		f[i].s =f[i].a *f[i].b ; 
	}
	for(int i=0;i<n;i++)
	{
		cout<<f[i].a <<" "<<f[i].b<<" "<<f[i].s<<" "<<f[i].c<<endl;
	}
	return 0;
 }

