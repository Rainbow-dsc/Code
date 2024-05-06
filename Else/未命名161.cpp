#include<iostream>
using namespace std;
int y,m,d,sum=0,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Sdate(int n,int y,int r)
{
	if(n%400==0||n%4==0&&n%100!=0) a[2]=29;
	else a[2]=28;
	for(int i=1;i<y;i++) sum+=a[i];
	return sum+r;
}
int main()
{
	cin>>y>>m>>d;
	cout<<Sdate(y,m,d);
	return 0;
}


