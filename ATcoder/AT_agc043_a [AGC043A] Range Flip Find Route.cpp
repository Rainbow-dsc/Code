//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
#define maxn 105
using namespace std;
int n,m;
char a[maxn][maxn];
int dp[maxn][maxn];
signed main(){
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	dp[1][1]=(a[1][1]=='#');
	for(int i=2;i<=m;i++) dp[1][i]=dp[1][i-1]+(a[1][i-1]=='.'&&a[1][i]=='#');
	for(int i=2;i<=n;i++) dp[i][1]=dp[i-1][1]+(a[i-1][1]=='.'&&a[i][1]=='#');
    for(int i=2;i<=n;i++) for(int j=2;j<=m;j++) dp[i][j]=min(dp[i-1][j]+(a[i-1][j]=='.'&&a[i][j]=='#'),dp[i][j-1]+(a[i][j-1]=='.'&&a[i][j]=='#'));
	printf("%d",dp[n][m]);
	return 0;
}
