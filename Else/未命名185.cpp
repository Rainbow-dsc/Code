#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	int d;
	int h;
}s[4000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i].d>>s[i].h;
	for(int i=0;i<n;i++)
		cout<<s[i].d<<' '<<s[i].h<<' '<<(s[i].d*s[i].h)/2<<endl; 
	return 0;
}


