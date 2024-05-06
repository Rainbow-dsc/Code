#include <bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int hh,tt,n;
struct aa {
	int h,t,k;
} a[maxn];
int dp[maxn][maxn];
signed main() {
	scanf("%lld %lld %lld",&hh,&tt,&n);
	for(int i=1; i<=n; i++) scanf("%lld %lld %lld",&a[i].h,&a[i].t,&a[i].k);
	for(int i=1; i<=n; i++) for(int j=hh; j>=a[i].h; j--) for(int ttt=tt; ttt>=a[i].t; ttt--) dp[j][ttt]=max(dp[j][ttt],dp[j-a[i].h][ttt-a[i].t]+a[i].k);
	printf("%lld",dp[hh][tt]);
	return 0;
}
