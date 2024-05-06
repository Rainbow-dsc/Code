#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,a[maxn],dp[maxn],k;
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) dp[i]=1e18;
    dp[1]=0;
    for(int i=1;i<=n-1;i++) for(int j=1;j<=k;j++) dp[i+j]=min(dp[i+j],dp[i]+abs(a[i]-a[i+j]));
    printf("%lld",dp[n]);
    return 0;
}