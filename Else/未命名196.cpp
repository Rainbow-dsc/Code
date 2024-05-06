#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d>>e>>f;
	int h=(a>b?a:b)>c?(a>b?a:b):c;
	int i=(a<b?a:b)<c?(a<b?a:b):c;
	int j=a+b+c-h-i;
	int k=(d>e?d:e)>f?(d>e?d:e):f;
	int l=(d<e?d:e)<f?(d<e?d:e):f;
	int m=d+e+f-k-l;
	int s=j<m?j:m;
	cout<<s;
	return 0;
}


