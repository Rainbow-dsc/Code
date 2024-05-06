#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,q;
int qpow(int a,int b,int mod) {
	int ans=1;
	while(b) {
		if(b&1) ans=ans%mod*a%mod;
		a=a%mod*a%mod;
		b>>=1;
	}
	return ans%mod;
}
signed main(){
	scanf("%lld %lld %lld",&a,&b,&q);
	printf("%lld^%lld mod %lld=%lld",a,b,q,qpow(a,b,q));
	return 0;
}
