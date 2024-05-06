#include<iostream>
using namespace std;

int main()
{
	int a[110] , b[110] , n ; 
	cin >> n ;
	for(int i=0 ; i<n ; i++)
	{
		cin >> a[i] >> b[i] ;
	}
	for(int i=0 ; i<n ; i++)
	{
		cout << a[i] << " " << b[i] << " " << a[i]*b[i]/2 << endl ;
	}
	return 0;
}
