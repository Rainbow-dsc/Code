#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,m,a,b,c,d;
int ans[maxn],faa[maxn],deg[maxn],deep[maxn],fa[maxn][31],val[maxn],dis[maxn];
bool vis[maxn];
struct aa {
	int v,w;
	bool operator < (const aa &x) const {
		return x.w<w;
	}
};
vector <aa> P[maxn];
priority_queue <aa> C;
int find(int x) {
	if(x==faa[x]) return x;
	else return faa[x]=find(faa[x]);
}
void dfs1(int x) {
	if(x==b) return ;
	for(int i=0; i<P[x].size(); i++) {
		P[x][i].w=0;
		dfs1(P[x][i].v);
	}
}
void Dj(int s) {
	ans[s]=0;
	C.push({s,0});
	while(!C.empty()) {
		aa tp=C.top();
		C.pop();
		if(vis[tp.v]) continue;
		vis[tp.v]=true;
		for(int i=0; i<P[tp.v].size(); i++) {
			aa now=P[tp.v][i];
			if(ans[now.v]>ans[tp.v]+now.w) {
				ans[now.v]=ans[tp.v]+now.w;
				C.push({now.v,ans[now.v]});
			}
		}
	}
}
int LCA(int x,int y) {
	if(deep[x]>=deep[y]) swap(x,y);
	int tmp=deep[y]-deep[x], ans=0;
	for(int i = 0; tmp; i ++,tmp >>= 1) if(tmp&1) y=fa[y][i];
	if(y == x) return x;
	for(int i = 30; i >= 0; i --) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
void dfs(int x,int frt) {
	fa[x][0] = frt;
	deep[x] = deep[fa[x][0]] + 1;
	for(int i = 1; i <= 31; i ++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i = 0; i < P[x].size(); i ++) {
		aa now = P[x][i];
		if(P[x][i].v == frt) continue;
		val[now.v] = now.w;
		dis[now.v] = dis[x] + now.w;
		dfs(P[x][i].v,x);
	}
}
signed main() {
	freopen("mission.in","r",stdin);
	freopen("mission.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	for(int i=1; i<=n; i++) faa[i]=i;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		int fu=find(u),fv=find(v);
		if(fu!=fv) faa[fu]=fv;
		P[u].push_back({v,w});
		P[v].push_back({u,w});
		deg[u]++,deg[v]++;
	}
	int cnt1=0,cnt2=0,cnt=0;
	for(int i=1; i<=n; i++) {
		if(deg[i]==1) cnt1++;
		if(deg[i]==2) cnt2++;
	}
	for(int i=1; i<=n; i++) ans[i]=1e18;
	if(cnt1==2&&cnt2==n-2) {
		dfs1(a);
		Dj(c);
		printf("%lld",ans[d]);
		return 0;
	}
	for(int i=1; i<=n; i++) if(faa[i]==i) cnt++;
	if(n==m+1&&cnt==1) {
		dfs(1,0);
		printf("%lld",dis[c]+dis[d]-2*dis[LCA(c,d)]);
	}
	Dj(c);
	cout<<ans[d]<<endl;
	return 0;
}
/*
7 6
3 4
6 7
1 2 1
2 3 1
2 4 1
1 5 1
5 6 1
5 7 1
*/
