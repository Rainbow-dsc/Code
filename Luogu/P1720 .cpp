#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	printf("%.2lf",(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5));
	return 0;
}
