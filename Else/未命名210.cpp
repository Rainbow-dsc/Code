#include<iostream>

using namespace std;

struct stu
{
	int a;
	int b;
	int zc;
	int mj; 
} 
s[4000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].a*s[i].b<<' '<<(s[i].a+s[i].b)*2<<endl;	 
	}
	return 0;
}


