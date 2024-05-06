#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int mid,max,min;
	mid=(a<b)?a:b;
	mid=(mid<c)?mid:c;
	max=(a>b)?a:b;
	max=(max>c)?max:c;
	min=a+b+c-max-mid;
	cout<<max<<min<<mid;
	return 0;
}

