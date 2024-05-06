#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	int c;
	int k;
}s[4000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i].c>>s[i].k;
	for(int i=0;i<n;i++)
		cout<<s[i].c<<' '<<s[i].k<<' '<<(s[i].c+s[i].k)*2<<' '<<s[i].c*s[i].k<<aendl; 
	return 0;
}


