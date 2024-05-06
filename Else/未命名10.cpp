#include<iostream>
#include<windows.h>
#include<time.h> 
using namespace std;
int main()
{
	int n,i;
	srand(time(NULL));//设置随机数种子 
	n=rand()%30+1;//产生随机数 
	cout<<"傻子，请输入您的彩票号码：\n"; 
	cin>>i; 
	while(i!=n)
	{
		cout<<"傻子，您没有中奖，请重新购买：\n";
		cin>>i;
	} 
	cout<<"恭喜你，傻子中了5000万！！！"; 
	return 0;
}

