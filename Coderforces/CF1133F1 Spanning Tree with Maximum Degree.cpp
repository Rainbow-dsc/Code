#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,m;
int rt;
int du[maxn],fa[maxn];
int u[maxn],v[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		scanf("%lld%lld",&u[i],&v[i]);
		du[u[i]]++;
		du[v[i]]++;
	}
	for(int i=1; i<=n; i++) if(du[i]>du[rt]) rt=i;
	for(int i=1; i<=m; i++) {
		if(u[i]==rt||v[i]==rt) {
			int fu=find(u[i]);
			int fv=find(v[i]);
			fa[fu]=fv;
			printf("%lld %lld\n",v[i],u[i]);
		}
	}
	for(int i=1; i<=m; i++) {
		if(find(u[i])!=find(v[i])) {
			int fu=find(u[i]);
			int fv=find(v[i]);
			fa[fu]=fv;
			printf("%lld %lld\n",u[i],v[i]);
		}
	}
	return 0;
}

