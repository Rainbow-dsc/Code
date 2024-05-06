#include <bits/stdc++.h>
#define int long long
#define maxn 250007
using namespace std;
int T,n;
int a[maxn],dp[maxn];
signed main() {
	scanf("%lld",&T);
	while(T--) {
		memset(dp,0xcf,sizeof(dp));
		scanf("%lld",&n);
		int ans=n;
		dp[0]=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) for(int j=a[i];j<=maxn;j++) dp[j]=max(dp[j],dp[j-a[i]]+1);
		for(int i=1;i<=n;i++) if(dp[a[i]]>=2) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}

