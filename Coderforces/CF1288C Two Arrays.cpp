#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define maxn 1005 
using namespace std;
const int mod=1e9+7;
int n,m;
int dp[maxn][maxn];
signed main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) dp[0][i]=1;
	m*=2;
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) for(int k=1;k<=j;k++) dp[i][j]=(dp[i-1][k]+dp[i][j])%mod;
	printf("%lld",dp[m][n]);
    return 0;
}
