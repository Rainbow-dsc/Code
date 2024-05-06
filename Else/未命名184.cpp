#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	char name[30];
	char sex[30];
	int age;
} s[100];
int main()
{
	for(int i=0;i<4;i++)
	{
		cin>>s[i].name>>s[i].sex>>s[i].age;
	} 
	for(int i=0;i<4;i++)
	{
		cout<<s[i].name<<' '<<s[i].sex<<' '<<s[i].age<<endl;
	} 
	return 0;
}


