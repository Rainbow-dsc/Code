#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n;
double dp[maxn];
vector <int> P[maxn];
void dfs(int x,int fa) {
	int cnt=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa) continue;
		dfs(now,x);
		dp[x]+=(dp[now]+1.0);
		cnt++;
	}
	if(cnt) dp[x]/=(double)cnt;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%lld %lld",&u,&v);
		P[u].push_back(v);
		P[v].push_back(u);
	}
	dfs(1,0);
	printf("%.15lf",dp[1]);
    return 0;
}

