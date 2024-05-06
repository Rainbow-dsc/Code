#include <bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int n,x;
int lose[maxn],win[maxn],use[maxn];
int dp[maxn];
signed main() {
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&lose[i],&win[i],&use[i]);
	for(int i=1;i<=n;i++) {
		for(int j=x;j>=use[i];j--) dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
		for(int j=use[i]-1;j>=0;j--) dp[j]+=lose[i];
	}
	printf("%lld",5*dp[x]);
	return 0;
}

