#include<bits/stdc++.h>
#define int long long
#define maxn 300005
using namespace std;
int t,n;
vector <int> P[maxn];
int siz[maxn],dp[maxn];
void dfs(int x,int fa) {
	siz[x]=1,dp[x]=0;
	int sum=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa) continue;
		dfs(now,x);
		sum+=dp[now];
		siz[x]+=siz[now];
	}
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now!=fa) dp[x]=max(dp[x],sum-dp[now]+siz[now]-1);
	}
}
signed main(){
	scanf("%lld",&t);
	while(t--) {
		memset(P,0,sizeof(P));
		scanf("%lld",&n);
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%lld %lld",&u,&v);
			P[u].push_back(v);
			P[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",dp[1]);
	}
    return 0;
}

