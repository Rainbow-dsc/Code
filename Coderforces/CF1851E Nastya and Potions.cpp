#include<bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int T;
int c[maxn];
int cost[maxn],ans[maxn];
vector <int> P[maxn];
int dfs(int x){
	if(ans[x]<1e18) return ans[x];
	ans[x]=min(ans[x],c[x]);
	int sum=0;
	for(int i=0;i<P[x].size();i++) sum+=dfs(P[x][i]);
	if(P[x].size()==0) sum=1e18;
	ans[x]=min(ans[x],sum);
	return ans[x];
}
signed main(){
	scanf("%lld",&T);
	while(T--) {
		int n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++) ans[i]=1e18;
		memset(P,0,sizeof(P));
		for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
		for(int i=1;i<=k;i++) {
			int p;
			scanf("%lld",&p);
			ans[p]=0;
		}
		for(int i=1;i<=n;i++) {
			int m;
			scanf("%lld",&m);
			for(int j=1;j<=m;j++) {
				int e;
				scanf("%lld",&e);
				P[i].push_back(e);
			}
		}
		for(int i=1;i<=n;i++) cout<<dfs(i)<<" ";
		puts("");
	}
	return 0;
}

