#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char a[1000]; 
int main()
{
	gets(a); 
	int len;
	for(int i=0;i<strlen(a);i++) 
    {
    if(a[i]<='9'&&a[i]>='0')  
    {
        while(a[i]<='9'&&a[i]>='0') 
        {
   		 cout<<a[i];
   		 i++;
         }
    cout<<" ";
    }
    }
    return 0;	
}
 

