#include<bits/stdc++.h>
using namespace std;
int n,a;
bool flag=true;
int main(){
	cin>>a;
	if(a<0){
		flag=false;
		a=-a;
	}
	while(a>0){
		n=n*10+a%10;
		a/=10;
	}
	if(flag==false) cout<<"-";
	cout<<n;
	return 0;
}
