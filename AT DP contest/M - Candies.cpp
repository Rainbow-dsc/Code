#include<bits/stdc++.h>
#define int long long
#define maxn 105
#define P_maxn (int)(1e5+5)
#define mod (int)(1e9+7)
using namespace std;
int n,k;
int a[maxn];
int dp[maxn][P_maxn],sum[maxn][P_maxn];//表示第i个人,已经用掉j个糖的方案数
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    dp[1][0]=sum[1][0]=1;
    for(int i=1;i<=k;i++) {
        if(i<=a[1]) dp[1][i]=1;
        else dp[1][i]=0;
        sum[1][i]=dp[1][i]+sum[1][i-1];
    }//处理第一个数的方案数
    for(int i=2;i<=n;i++) {
        dp[i][0]=sum[i][0]=1;
        for(int j=1;j<=k;j++) {
            if(j<=a[i]) dp[i][j]=sum[i-1][j]%mod;
            else dp[i][j]=(sum[i-1][j]-sum[i-1][j-a[i]-1]+mod)%mod;
            sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
        }
    }
    printf("%lld",dp[n][k]);
    return 0;
}