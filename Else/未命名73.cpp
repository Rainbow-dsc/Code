#include<iostream>
using namespace std;
int main()
{
	int a,b;
	a=(!(1<4))&&(!(3>9))||(1>4)&&(3>9);
	b=(!(1<4))||(!(3>9))&&(1<4)||(3>9);
	cout<<a<<endl<<b;
	return 0;
}

