#include<iostream>
using namespace std;
int main()
{
	int sum=0; 
	for(int i=123;i<=987;i++)
	{
		int o=i%10;
		int p=i/10%10;
		int u=i/100;
		if(o!=p&&o!=u&&p!=u&&o!=0&&u!=0&&p!=0)
		{
			sum++;
			cout<<i<<" ";
			if(sum==10)
			{
				cout<<endl;
				sum=0;
			}
		} 
	}  
	return 0;
}


