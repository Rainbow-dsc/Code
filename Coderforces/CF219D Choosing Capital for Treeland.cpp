#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n;
struct aa{
	int to,flag;
};
vector <aa> P[maxn];
int dp[maxn];
void dfs1(int x,int fa) {
	for(int i=0;i<P[x].size();i++) {
		aa now=P[x][i];
		if(now.to==fa) continue;
		dfs1(now.to,x);
		dp[x]+=dp[now.to]+now.flag;
	}
}
void dfs2(int x,int fa) {
	for(int i=0;i<P[x].size();i++) {
		aa now=P[x][i];
		if(now.to==fa) continue;
		dp[now.to]=dp[x]+(now.flag?-1:1);
		dfs2(now.to,x);
	}
}
signed main() {
	while(scanf("%lld",&n)!=EOF) {
		int ans=1e18;
		memset(P,0,sizeof(P));
		memset(dp,0,sizeof(dp));
		for(int i=1; i<n; i++) {
			int a,b;
			scanf("%lld %lld",&a,&b);
			P[a].push_back({b,0});
			P[b].push_back({a,1});
		}
		dfs1(1,-1),dfs2(1,-1);
		for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) if(ans==dp[i]) printf("%lld ",i);
	}
	return 0;
}

