#include<iostream>
using namespace std;
int main()
{
	int a=666666,b=888888;
	cout<<"请输入您的QQ账号:\n";
	cin>>a;
	cin>>b; 
	while(a!=666666&&b!=888888)
	{	
		if(a!=666666||b!=888888)
		{
			cout<<"请再输入您的账户或密码：\n";
		} 
		cout<<"请再输入您的账户或密码：\n";
		cin>>a; 
		cin>>b;
	}	
	cout<<"登陆成功\n";
	return 0;
}
