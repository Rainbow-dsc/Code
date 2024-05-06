#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
struct aa {
	int to,w;
};
struct query {
	int x,y,lca,d;
} A[maxn];
int n,m,tot,L,R;
vector <aa> P[maxn];
int fa[maxn][40],deep[maxn];
int C[maxn],dis[maxn],val[maxn];
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
		if(P[x][i].to == frt) continue;
		val[now.to] = now.w;
		dis[now.to] = dis[x] + now.w;
		dfs(P[x][i].to,x);
	}
}
void summ(int x,int front) {
	for(int i = 0; i < P[x].size(); i ++) {
		int y = P[x][i].to;
		if(y == front) continue;
		summ(y,x);
		C[x] += C[y];
	}
}
bool check(int mid) {
	int sum = 0,maxx = -1;
	memset(C,0,sizeof(C));
	for(int i = 1; i <=m; i ++) if(A[i].d>mid) C[A[i].x]++,C[A[i].y]++,C[A[i].lca]-=2,sum++;
	if(sum==0) return true;
	summ(1,1);
	for(int i=1; i<=n; i++) {
		if(C[i] == sum&&dis[i]-dis[fa[i][0]]>=R-mid) return true;
	}
	return false;
}
int search(int l,int r) {
	int res = 1e9 + 7;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(check(mid)) {
			res = min(mid,res), r = mid - 1;
		} else l = mid + 1;
	}
	return res;
}
signed main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<n; i++) {
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		P[a].push_back({b,t});
		P[b].push_back({a,t});
	}
	dfs(1,0);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&A[i].x,&A[i].y);
		A[i].lca = LCA(A[i].x,A[i].y);
		A[i].d = dis[A[i].x] + dis[A[i].y] - 2 * dis[A[i].lca];
		R = max(R,A[i].d);
	}
	printf("%d\n",search(0,R));
	return 0;
}
