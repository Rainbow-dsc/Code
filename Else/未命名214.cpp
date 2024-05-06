#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct stu
{
	char name[51];
	int b;
	int c; 
} s[100];
bool px(stu a,stu r)
{
	if(a.b!=r.b) return a.b<r.b;
	else if(strlen(a.name)!=strlen(r.name)) return strlen(a.name)<strlen(r.name);
	else return a.c<r.c;
}
int main()
{
	int n;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>s[i].name>>s[i].b>>s[i].c;
	}
	sort(s,s+n,px);
	for(int i=0;i<n;i++)
	{
		cout<<s[i].name<<' '<<s[i].b<<' '<<s[i].c<<endl;
	}
	return 0;
}


