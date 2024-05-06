#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n,a[1001],dp[1001];
signed main() {
	scanf("%lld",&n);
	for(i=1; i<=n/2; i++) for(j=2; i*j<=n; j++) a[i*j]+=i;
	for(i=1; i<=n; i++) for(j=i; j<=n; j++) dp[j]=max(dp[j],dp[j-i]+a[i]);
	printf("%lld",dp[n]);
	return 0;
}
