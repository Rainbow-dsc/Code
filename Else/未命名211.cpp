#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
//姓名，班级，学号信息，输入学生学号 
struct stu
{
	char name[4000];
	char cla[100];
	char id[4000];
}
a[4040]; 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].name>>a[i].cla>>a[i].id;
	}
	char op[4000];
	cin>>op;
	for(int i=0;i<n;i++)
	{
		if(strcmp(op,a[i].name)==0)
		{
			cout<<a[i].name<<' '<<a[i].cla<<' '<<a[i].id;
		}
	}
	return 0;
}


