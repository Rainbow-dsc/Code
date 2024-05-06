#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int T,n;
int l[maxn],r[maxn],dp[maxn][10];
vector <int> P[maxn];
void dfs(int x,int fa) {
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa) continue;
		dfs(now,x);
		dp[x][0]+=max(dp[now][1]+abs(r[now]-l[x]),dp[now][0]+abs(l[now]-l[x]));
        dp[x][1]+=max(dp[now][0]+abs(l[now]-r[x]),dp[now][1]+abs(r[now]-r[x]));
	}
}
signed main(){
	scanf("%lld",&T);
	while(T--) {
		memset(P,0,sizeof(P));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(dp,0,sizeof(dp));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) {
			scanf("%lld %lld",&l[i],&r[i]);
			dp[i][0]=dp[i][1]=0;
		}
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%lld %lld",&u,&v);
			P[u].push_back(v);
			P[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
    return 0;
}

