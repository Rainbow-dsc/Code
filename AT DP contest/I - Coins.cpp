#include<bits/stdc++.h>
#define int long long
#define maxn 3005
#define mod (int)(1e9+7)
using namespace std;
int n;
double ans;
double p[maxn],dp[maxn][maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0]=dp[i-1][0]*(1-p[i]);
        for(int j=1;j<=i;j++) dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1.0-p[i]);
    }
    for(int i=1;i<=n;i++) if(2*i>n) ans+=dp[n][i];
    printf("%.10lf",ans);
    return 0;
}