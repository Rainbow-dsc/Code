#include<iostream>
using namespace std;
int s(int a,int b)
{
	if(a<b||a==b) cout<<'b';
	else cout<<'a';
}
int main()
{
	int a,b;
	cin>>a>>b;
	s(a,b);
	return 0;
}


