#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,m,k;
int col[maxn],fa[maxn],siz[maxn];
vector <int> P[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1; i<=n; i++) scanf("%lld",&col[i]);
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%lld%lld",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu!=fv) fa[fu]=fv;
	}
	for(int i=1; i<=n; i++) P[find(i)].push_back(i);
	for(int i=1; i<=n; i++) {
		int mx=0;
		for(int j=0; j<P[i].size(); j++) siz[col[P[i][j]]]++;
		for(int j=0; j<P[i].size(); j++) if(mx<siz[col[P[i][j]]]) mx=siz[col[P[i][j]]];
		for(int j=0; j<P[i].size(); j++) siz[col[P[i][j]]]--;
		ans+=P[i].size()-mx;
	}
	printf("%lld",ans);
	return 0;
}
