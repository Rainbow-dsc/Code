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
		cout<<"isosceles right triangle";	//����ֱ�� 
	}
	else	if(a==60&&b==60&&c==60&&a+b+c==180)
	{
		cout<<"equilateral triangle";	//�ȱ�����
	}
	else	if(a==b&&b!=c&&c!=a&&a+b+c==180)	//�������� 
	{
		cout<<"isosceles triangle";
	}
	else	if(a>90&&b<90&&c<90&&a+b+c==180||b>90&&a<90&&c<90&&a+b+c==180||c>90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"obtuse triangle"; 	//�۽�����
	}	
	else	 if(a==90&&b<90&&c<90&&a+b+c==180||b==90&&a<90&&c<90&&a+b+c==180||c==90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"right triangle"; //ֱ������ 
	}
	else	if(a<90&&b<90&&c<90&&a+b+c==180||b<90&&a<90&&c<90&&a+b+c==180||c<90&&a<90&&b<90&&a+b+c==180) 
	{
		cout<<"acute triangle"; //������� 
	}
	return 0;
}


