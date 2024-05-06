#include<bits/stdc++.h>
#define int long long
#define maxn 30
#define maxn_n (int)(1<<21)
#define mod (int)(1e9+7)
using namespace std;
int n;
int a[maxn][maxn],dp[maxn][(int)(3e6)];//dp表示左边前i个点匹配右边集合的方案数
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
    dp[0][0]=1;
    for(int j=1;j<maxn_n;j++) {
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=(j>>(i-1))&1;
        for(int i=1;i<=n;i++) {
            if(((j>>(i-1))&1)==0) continue;
            if(a[cnt][i]) dp[cnt][j]=(dp[cnt][j]+dp[cnt-1][j^(1<<(i-1))])%mod;
        }
    }
    printf("%lld",dp[n][(1<<n)-1]);
    return 0;
}