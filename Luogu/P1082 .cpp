#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,x,y;
int exgcd(int a,int b) {
	int d;
	if(b==0) {
		x=1,y=0;
		return a;
	}
	d=exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return d;
}
signed main(){
	scanf("%lld %lld",&a,&b);
	exgcd(a,b);
	printf("%lld",(x+b)%b);
	return 0;
}

