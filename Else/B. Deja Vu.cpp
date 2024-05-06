#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int a[maxn],x[maxn],vis[maxn];
int lg[31];
int n,q,ans[maxn],t;
int solve(int t) {
	int p=0,k=0;
	for(int i=1; i<=q; i++) {
		if(p==0&&x[i]<=t) k=x[i]-1,p+=lg[x[i]-1];
		if(x[i]<=k) {
			p+=lg[x[i]-1];
			k=x[i]-1;
		}
	}
	return p;
}
signed main() {
	scanf("%lld",&t);
	lg[0]=1;
	for(int i=1; i<=30; ++i) lg[i]=lg[i-1]*2;
	while(t--) {
		memset(vis,0,sizeof(vis));
		scanf("%lld %lld",&n,&q);
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			for(int j=0; j<=30; ++j) if(a[i]%lg[j]==0) vis[i]=j;
		}
		for(int i=1; i<=q; i++) scanf("%lld",&x[i]);
		for(int i=0; i<=30; i++) ans[i]=solve(i);
		for(int i=1; i<=n; i++) printf("%lld ",a[i]+ans[vis[i]]);
		puts("");
	}
	return 0;
}

