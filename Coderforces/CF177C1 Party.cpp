#include<bits/stdc++.h>
#define maxn 2005
#define int long long
using namespace std;
int n,k,m;
int fa[maxn];
int vis[maxn];
int ansn[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main() {
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=k; i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		fa[find(x)]=find(y);
	}
	scanf("%lld",&m);
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(find(x)!=find(y)) continue;
		else vis[find(x)]=1,vis[find(y)]=1;
	}
	for(int i=1;i<=n;i++) ansn[find(i)]++;
	int ans=0;
	for(int i=1;i<=n;i++) {
		if(vis[i]!=1||fa[i]!=i) ans=max(ans,ansn[i]);
	}
	printf("%lld",ans);
	return 0;
}

