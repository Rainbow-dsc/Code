#include <bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,m,ans=0;
int a[maxn];
vector <int> P[maxn];
void dfs(int now,int fa,int sum){
	if(P[now].size()==1&&now!=1){
		if(sum<=m) ans++;
		return ;
	} 
	for(int i=0;i<P[now].size();i++) {
		int v=P[now][i];
		if(v==fa) continue;
		if(a[v]==0) dfs(v,now,0);
		else if(sum+1<=m) dfs(v,now,sum+1); 
	}
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%lld%lld",&u,&v);
		P[u].push_back(v);
		P[v].push_back(u);
	}
	dfs(1,0,a[1]);
	printf("%lld",ans);
	return 0;
}

