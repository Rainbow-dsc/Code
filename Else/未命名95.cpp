#include<iosstream>
using namespace std;
int n,a[100]; 
int main()
{
	cin>>n;
 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	cout<<a[0];
	for(int i=2;i<n;i++)
	{
		if(i%2==0)
		{
			cout<<" "<<a[i];			
		}
	}
	cout<<endl;
	cout<<a[1];
	for(int i=3;i<n;i++)
	{
		if(i%2==1)
		{
			cout<<" "<<a[i];
		}
	}
	return 0;
}

