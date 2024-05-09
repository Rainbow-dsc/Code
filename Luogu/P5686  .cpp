#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 500010
#define int long long
using namespace std;
int n;
int a[maxn],b[maxn];
int prea[maxn],preb[maxn];
int suma,sumb,ans;
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) { scanf("%lld",&a[i]); prea[i]=(prea[i-1]+a[i])%mod; }
	for(int i=1;i<=n;++i) { scanf("%lld",&b[i]); preb[i]=(preb[i-1]+b[i])%mod; }
	for(int i=1;i<=n;i++) (ans+=(((n+1)*prea[i])%mod)*preb[i])%=mod,suma=(suma+prea[i])%mod,sumb=(sumb+preb[i])%mod;
	int tot=(suma*sumb)%mod;
	ans=(ans-tot+mod)%mod;
	printf("%lld",ans);
	return 0;
}