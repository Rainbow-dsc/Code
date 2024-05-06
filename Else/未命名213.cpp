#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct stu
{
	char name[51];
	int num;
	int score; 
} s[3];
bool px(stu a,stu b)
{
	if(a.score!=b.score) return a.score>b.score;
	else if(a.num!=b.num) return a.num<b.num;
}
int main()
{
	for(int i=0;i<3;i++)
	{
		cin>>s[i].num>>s[i].name>>s[i].score;
	}
	sort(s,s+3,px);
	for(int i=0;i<3;i++)
	{
		cout<<s[i].num<<' '<<s[i].name<<' '<<s[i].score<<endl;
	}
	return 0;
}


