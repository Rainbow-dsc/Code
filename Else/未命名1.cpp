#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	a=(a+5)%3;
	b=(b+5)%3;
	c=(c+5)%3;
	int mid,max,min;
	min = (a<b)?a:b;
	min = (min<c)?min:c;
	max =(a>b) ?a:b;
	max=(max>c) ?max:c;
	mid=a+b+c-max-min;
	cout<<"wozuipiaoliang"<<min<<mid<<max;
	return 0;
}

