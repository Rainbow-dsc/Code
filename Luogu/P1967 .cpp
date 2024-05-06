#include<bits/stdc++.h>
#define int long long
#define maxn 100004
using namespace std;
int n,m;
int faa[maxn],fa[maxn][31],deep[maxn],w[maxn][31];
bool vis[maxn];
struct A { int to,w; };
vector <A> P[maxn],Pp[maxn];
struct Acin { int x,y,z; } a[maxn];
bool cmp(Acin p,Acin pp) { return p.z>pp.z; }
int find(int x) {
	if(faa[x]==x) return faa[x];
	return faa[x]=find(faa[x]);
}
void dfs(int x) {
	vis[x]=true;
	for(int i=0; i<Pp[x].size(); i++) {
		A now=Pp[x][i];
		if(vis[now.to]) continue;
		deep[now.to]=deep[x]+1;
		w[now.to][0]=now.w;
		fa[now.to][0]=x;
		dfs(now.to);
	}
}
int LCA(int x, int y) {
	if(find(x)!=find(y)) return -1;
	int ans=1e18;
	if(deep[x]>deep[y]) swap(x,y);
	for(int i=20; i>=0; i--) if(deep[fa[y][i]]>=deep[x]) ans=min(ans, w[y][i]),y=fa[y][i];
	if(x==y) return ans;
	for(int i=20; i>=0; i--)
		if(fa[x][i]!=fa[y][i]) {
			ans=min(ans, min(w[x][i],w[y][i]));
			x=fa[x][i],y=fa[y][i];
		}
	ans=min(ans,min(w[x][0], w[y][0]));
	return ans;
}
signed main() {
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
		P[a[i].x].push_back({a[i].y,a[i].z});
		P[a[i].y].push_back({a[i].x,a[i].z});
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1; i<=n; i++) faa[i]=i;
	for(int i=1; i<=m; i++) {
		if(find(a[i].x)!=find(a[i].y)) {
			int fx=find(a[i].x),fy=find(a[i].y);
			faa[fx]=fy;
			Pp[a[i].x].push_back({a[i].y,a[i].z});
			Pp[a[i].y].push_back({a[i].x,a[i].z});
		}
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			deep[i]=1;
			dfs(i);
			fa[i][0]=i,w[i][0]=1e18;
		}
	}
	for(int i=1; i<=20; i++)
		for(int j=1; j<=n; j++) {
			fa[j][i]=fa[fa[j][i-1]][i-1];
			w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);
		}
	int q;
	scanf("%lld",&q);
	while(q--) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld",LCA(x,y));
		if(q!=0) puts(""); 
	}
	return 0;
} 
