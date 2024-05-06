#include<bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int n,a[maxn],dp[maxn][maxn];
int sum[maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e18;
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int l=1;l<=n;l++) {//1.len
        for(int i=1;i<=n;++i) {//2.left
            int j=i+l;
            if(j>n) continue;
            for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            // for(int k=i;k<=j;k++) dp[i][j]+=a[k];
        }
    }
    printf("%lld",dp[1][n]);
    return 0;
}