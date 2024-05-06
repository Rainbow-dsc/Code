#include<bits/stdc++.h>
#define maxn 500005
#define mod 1000000007
#define int long long
using namespace std;
int n,k;
int fa[maxn];
int sum[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int qpow(int a,int b) {
    int res = 1,base = a;
    while(b) {
        if(b & 1) (res *= base) %= mod;
        (base *= base) %= mod;
        b >>= 1;
    }
    return res;
} // ¿ìËÙÃİ
signed main() {
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<n; i++) {
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		if(w==0) {
			if(find(u)!=find(v)) {
				fa[find(u)]=find(v);
			}
		}
	} 
	for(int i=1; i<=n; i++) sum[find(i)]++;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(sum[i]>0) {
			cnt=(cnt+qpow(sum[i],k))%mod;	
		}
	}
	printf("%lld",(qpow(n,k)-cnt+mod)%mod);
	return 0;
}

