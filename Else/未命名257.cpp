#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int mix((a>b?a:b)>c?(a>b?a:b):c);
	int min((a<b?a:b)<c?(a<b?a:b):c);
	int l=mix-min;
	cout<<l;
	return 0;
}


