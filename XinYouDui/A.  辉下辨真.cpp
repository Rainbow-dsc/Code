#include<bits/stdc++.h>
#define int long long
#define maxn 5010
#define pmod 998244353
using namespace std;
int n,m,f[maxn],g[maxn],ff[maxn];
signed main() {
	freopen("true.in","r",stdin);
	freopen("true.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	swap(n,m);
	for(int i=1; i<=n; i++)f[i]=(i*(i+1)/2)%pmod;
	for(int i=1; i<=n; i++) g[i]=f[n+1-i];
	int s=f[n];
	for(int k=2; k<=m; k++ ) {
		for(int i=1; i<=n; i++) ff[i]=(ff[i-1]+f[i])%pmod;
		for(int i=1; i<=n; i++) f[i]=i*(s-g[i+1])%pmod,f[i]-=ff[i-1];
		for(int i=1; i<=n; i++) f[i]=(f[i-1]+f[i])%pmod;
		for(int i=1; i<=n; i++) g[i]=f[n+1-i];
		s=f[n];
	}
	printf("%lld\n",(s+pmod)%pmod);
	return 0;
}
