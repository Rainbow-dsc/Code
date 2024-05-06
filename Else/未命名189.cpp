#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	char name[50],bj[10],id[7];
}s[4000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		 cin>>s[i].name>>s[i].bj>>s[i].id;
	}
	char a;
	 
	return 0;
 }

