#include<iostream>
using namespace std;
int main()
{
	string a;
	getline(cin,a);
	int len=a.size();
	int u=0;
	while(a[len-1]==' ')
	{
		len--;
	} 
	for(int i=len-1;i>=0;i--)
	{
		if(a[i]==' ')
		{
			break;
		}
		u=u+1;
	}
	cout<<u;
	return 0;
}


