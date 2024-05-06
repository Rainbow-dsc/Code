#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(1==m%2 || 2*n>m || 4*n<m)
	{
		cout<<"input error"<<endl;
		return 0;
	}
	int SJL,BWL;
	SJL=(m-2*n)/2;
	BWL=n-SJL;
	if(SJL>BWL)
	{
		cout<<"SJL"<<endl;
		return 0;
	}
	if(SJL<BWL)
	{
		cout<<"BWL"<<endl;
		return 0;
	}
	if(SJL=BWL)
	{
		cout<<"all die"<<endl;
		return 0;
	}
	return 0;
}

