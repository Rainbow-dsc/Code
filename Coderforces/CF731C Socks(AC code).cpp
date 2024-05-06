#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int a[200005],fa[200005],t[200005];
int ans=0,n,m,k;
vector<int> P[200005];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=m; i++) {
		int l,r;
		scanf("%lld%lld",&l,&r);
		int fx=find(l);
		int fy=find(r);
		if(fx!=fy) fa[fx]=fy;
	}
	for(int i=1; i<=n; i++) P[find(i)].push_back(i);
	for(int i=1; i<=n; i++) {
		int mx=0;
		for(int j=0; j<P[i].size(); j++) ++t[a[P[i][j]]];
		for(int j=0; j<P[i].size(); j++) if(mx<t[a[P[i][j]]]) mx=t[a[P[i][j]]];
		for(int j=0; j<P[i].size(); j++) --t[a[P[i][j]]];
		ans+=P[i].size()-mx;
	}
	printf("%lld\n",ans);
	return 0;
}
