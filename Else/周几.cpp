#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a; 
	switch(a%7)
		{
			case 0:cout<<"Sunday";break;
			case 1:cout<<"Monday";break;
			case 2:cout<<"Tuesday";break;
			case 3:cout<<"Wednsday";break;
			case 4:cout<<"Thursday";break;
			case 5:cout<<"Friday";break;
			case 6:cout<<"Saturday";break;
			default:;
		}
	return 0;
}

