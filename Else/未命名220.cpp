#include<iostream>
using namespace std;
int a,b,c,d,e,f,k; 
char h;
int main()
{
	cin>>a>>h>>b>>c>>h>>d;
	e=b*d;
	f=a*d+c*b;
	int M=min(e,f);
	for(int i=M;i>=0;i--)
	{
		if(e%i==0&&f%i==0)
		{
			k=i;
			break;
		}
	}
	e=e/k;
	f=f/k;
	if(f%e==0) cout<<f/e;
	else cout<<f<<'/'<<e;
	return 0;
}


