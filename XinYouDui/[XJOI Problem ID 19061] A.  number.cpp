#include<bits/stdc++.h>
#define int long long
#define maxn 1000001
#define mod 998244353
using namespace std;
int a[maxn]={1};
int power(int x) {
	int y=1,i=mod-2;
	while(i) {
		if(i&1) y=x*y%mod;
		x=x*x%mod;
		i=i>>1;
	}
	return y;
}
int n,w=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) a[i]=(a[i-1]<<1)%mod;
	for(int i=0;i<n;i++) w=w*(mod+a[n]-a[i])%mod;
	int s=1;
	for(int i=2;i<=n;i++) s=s*i%mod;
	printf("%lld\n",w*power(s)%mod);
	return 0;
}

