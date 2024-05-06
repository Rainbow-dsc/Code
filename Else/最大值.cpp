#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int min,mid,max,man;
	min=a<b?a:b;
	min=min<c?min:c;
	min=min<d?min:d;
	max=a>b?a:b;
	max=max>c?max:c;
	max=max>d?max:d;
	man=a>min?a:min;
	man=man<max?man:max;
	man=man<mid?man:mid; 
	mid=a+b+c+d-max-man-min;
	cout<<max;
	return 0;
}

