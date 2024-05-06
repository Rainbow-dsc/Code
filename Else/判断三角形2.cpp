#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	switch((a+b>c)&&(a+c>b)&&(b+c>a))
		{
			case 0:cout<<"no";break;
			case 1:switch((a==b)&&(a==c)&&(b==c))
				{
					case 1:cout<<"equilateral triangle";break;
					case 0:switch((a==b)||(a==c)||(b==c))
						{
							case 1:cout<<"isosceles triangle";break;
							case 0:switch((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
							{
								case 1:cout<<"right triangle";break;
								default :cout<<"other triangle";break;
							}	
					}	
				}
				
		}
	return 0;
}

