#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int min,mid,max;
	min=a<b?a:b;
	min=min<c?min:c;
	max=a>b?a:b;
	max=max>c?max:c;
	mid=a+b+c-max-min;
	cout<<max<<mid<<min; 
	return 0;
}
