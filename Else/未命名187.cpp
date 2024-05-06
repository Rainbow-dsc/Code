#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	int h;
	int k;
	int c;
	int d; 
}s[4000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i].h>>s[i].k;
	for(int i=0;i<n;i++)
		cout<<s[i].h<<' '<<s[i].k<<' '<<s[i].h*s[i].k<<' '<<(s[i].h+s[i].k)*2<<endl; 
	return 0;
}


