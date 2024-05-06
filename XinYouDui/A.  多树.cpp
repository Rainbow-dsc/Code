#include <bits/stdc++.h>
#define maxn 505
#define int long long
using namespace std;
int n,k;
vector<int> P[maxn];
int dis[maxn][maxn],cnt[maxn][maxn];
void dfs(int st,int x,int fa,int d) {
	dis[st][x]+=d;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa) continue;
		dfs(st,now,x,d+1);
	}
}
signed main() {
	freopen("trees.in", "r", stdin);
	freopen("trees.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for(int i=1; i<=k; i++) {
		memset(P,0,sizeof(P));
		for(int j=1; j<n; j++) {
			int u,v;
			scanf("%lld%lld",&u,&v);
			P[u].push_back(v);
			P[v].push_back(u);
		}
		for(int j=1;j<=n;j++) dfs(j,j,0,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=n;k++) if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
			printf("%lld ",cnt[i][j]);
		}
		puts("");
	}
	return 0;
}
