#include<bits/stdc++.h>
#define maxn (int)1e5 + 4
#define int long long
using namespace std;
int val[maxn],n,m,s,k;
vector<int> P[maxn],C[maxn];
bool vis[maxn];
struct aa {
	int step,id;
};
queue<aa> Q;
void bfs() {
	while(!Q.empty()) {
		int id=Q.front().id;
		int step=Q.front().step;
		Q.pop();
		for(int i=0; i<P[id].size(); i++) {
			int v=P[id][i];
			if(vis[v]==false) {
				vis[v]=true;
				Q.push({step+1,v});
				C[v].push_back(step+1);
			}
		}
	}
}
signed main() {
	scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
	for(int i=1; i<=n; i++) scanf("%lld",&val[i]);
	for(int i=1; i<=m; i++) {
		int a,b;
		scanf("%lld%lld",&a,&b);
		P[a].push_back(b);
		P[b].push_back(a);
	}
	for(int i=1; i<=k; i++) {
		while(!Q.empty()) Q.pop();
		for(int j=1; j<=n; j++) {
			vis[j]=false;
			if(val[j]==i) {
				Q.push({0,j});
				C[j].push_back(0);
				vis[j]=true;
			}
		}
		bfs();
	}
	for(int i=1; i<=n; i++) {
		sort(C[i].begin(),C[i].end());
		int res=0;
		for(int j=0; j<s; j++) res+=C[i][j];
		printf("%lld ",res);
	}
	return 0;
}
