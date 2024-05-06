#include<iostream>
using namespace std;
int main()
{
	string a,b,c,d;
	getline(cin,a);
	getline(cin,b);
	int len=a.size();
	int len1=b.size();
	int len2=0;
	int len3=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]!=' ')c+=tolower(a[i]); 
	}
	for(int i=0;i<len1;i++)
	{
		if(b[i]!=' ')d+=tolower(b[i]);
	}
	cout<<(c==d?"YES":"NO"); 
	return 0;
}


