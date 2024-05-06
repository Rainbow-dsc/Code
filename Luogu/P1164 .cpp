#include <bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n,m;
int a[maxn],dp[101][maxn];
signed main() {
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(j==a[i]) dp[i][j]=dp[i-1][j]+1;
			if(j>a[i]) dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			if(j<a[i]) dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][m];
	return 0;
}

