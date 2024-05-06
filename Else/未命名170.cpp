#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b+c!=180)
	{
		return 0;
	}
	else	if(a==90&&b==c||b==90&&a==c||c==90&&b==a)
	{
		cout<<"isosceles right triangle";	//等腰直角 
	}
	else	if(a==60&&b==60&&c==60&&a+b+c==180)
	{
		cout<<"equilateral triangle";	//等边三角
	}
	else	if(a==b&&b!=c&&c!=a&&a+b+c==180)	//等腰三角 
	{
		cout<<"isosceles triangle";
	}
	else	if(a>90&&b<90&&c<90&&a+b+c==180||b>90&&a<90&&c<90&&a+b+c==180||c>90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"obtuse triangle"; 	//钝角三角
	}	
	else	 if(a==90&&b<90&&c<90&&a+b+c==180||b==90&&a<90&&c<90&&a+b+c==180||c==90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"right triangle"; //直角三角 
	}
	else	if(a<90&&b<90&&c<90&&a+b+c==180||b<90&&a<90&&c<90&&a+b+c==180||c<90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"acute triangle"; //锐角三角 
	}
	return 0;
}


