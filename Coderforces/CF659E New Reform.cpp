#include <bits/stdc++.h>
#define int long long
#define maxn 100000
using namespace std;
int n,m;
vector <int> P[maxn];
int fa[maxn];
bool vis[maxn];
int find(int x) {
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		int fx=find(x),fy=find(y);
		if(fx!=fy) {
			fa[fx]=fy;
			if(vis[x]||vis[y]||vis[fx]||vis[fy]) vis[x]=vis[y]=vis[fx]=vis[fy]=1;
		}
		else vis[x]=vis[y]=vis[fx]=vis[fy]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(find(i)==i&&!vis[i]) ans++;
	printf("%lld",ans);
	return 0;
}

