#include<iostream>
using namespace std;
int main()
{
	int a=1,b=0,sum=0;
	while(a<10){
		b=0;
		while(b<10){
			if(a!=b)
			{
				sum=sum+a*1000+b*100+b*10+a;
			}
			b++;
		}
		a++; 
	}
	cout<<sum;
	return 0;
}

