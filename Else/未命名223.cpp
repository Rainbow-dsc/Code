#include<iostream>
using namespace std;
string a,b;
int len1,len2,flag=0,flag1=0;
int main()
{
	getline(cin,a);
	getline(cin,b);
	len1=a.size();
	len2=b.size(); 
	for(int i=0;i<len1;i++)
	{
		if(a[i]==b[0])
		{
			flag1=1;
			flag=0;
			for(int j=0;j<len2;j++)
			{
				if(a[i]!=b[j])
				{
					flag=1;
					break;
				}
				i++;
			} 
			if(flag==0)
			{
				cout<<"YES";
				return 0;
			}
		}
		
	}
	if(flag1==0||flag==1) cout<<"NO";
	return 0;
}


