#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d;
	e=a*60+b;
	f=c*60+e;
	int g=f-e;
	int k=g/60;
	int o=g-k*60;
	cout<<k<<' '<<g;
	return 0;
}
