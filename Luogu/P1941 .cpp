#include<bits/stdc++.h>
#define int long long
#define maxn 10005
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k;
int cnt=1,ans=0;
int x[maxn],y[maxn];
struct aa {
	int p,l,h;
} a[maxn];
bool cmp(aa x,aa y) {
	return x.p<y.p;
}
int dp[2][maxn];
signed main() {
	memset(dp,inf,sizeof(dp));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%lld%lld",&x[i],&y[i]);
	for(int i=1; i<=k; i++) scanf("%lld%lld%lld",&a[i].p,&a[i].l,&a[i].h);
	sort(a+1,a+k+1,cmp);
	for(int i=1; i<=m; i++) dp[0][i]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) dp[i%2][j]=inf;
		for(int j=x[i]+1; j<=x[i]+m; j++) dp[i%2][j]=min(dp[i%2^1][j-x[i]]+1,dp[i%2][j-x[i]]+1);//p=1,完全背包
		for(int j=m+1; j<=x[i]+m; j++) dp[i%2][m]=min(dp[i%2][m],dp[i%2][j]);//比m大的都是m
		for(int j=1; j<=m-y[i]; j++) dp[i%2][j]=min(dp[i%2][j],dp[i%2^1][j+y[i]]);//p=0,01背包
		if(i==a[cnt].p) {//如果这个地方有管道
			ans=inf;//主要每次都要初始化一次!
			for(int j=0; j<=a[cnt].l; j++) dp[i%2][j]=inf;
			for(int j=a[cnt].h; j<=m; j++) dp[i%2][j]=inf;
			for(int j=1; j<=m; j++) ans=min(dp[i%2][j],ans);
			if(ans==inf) {
				printf("0\n%lld",cnt-1);
				return 0;
			}
			cnt++;
		}
	}
	ans=inf;
	for(int i=1; i<=m; i++) ans=min(ans,dp[n%2][i]);
	printf("1\n%lld",ans);
	return 0;
}
