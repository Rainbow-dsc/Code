#include<bits/stdc++.h>
using namespace std;
long long n,a1;
char a;
int main(){
	cin>>n;
	while(cin>>a){
		if(a==' '||a=='\n') break;
		a1=(int)a-'0'+a1*10;
		a1%=n;
	}
	cout<<a1%n+1;
	return 0;
}
