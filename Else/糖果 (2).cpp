#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,sum[2005],a[2005],dp[2005][2005],s[2005][2005];
int Pow(int n,int k){
    if(k==1) return n;
    if(k==2) return (n*n);
    if(k==3) return (n*n*n);
}
signed main() {
    cin>>n>>k;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        dp[i][i]=0;
        s[i][i]=i;
    }
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            int w=Pow((sum[j]-sum[i-1]),k);
            for(int k=s[i][j-1];k<=s[i+1][j];k++) {
                if(dp[i][k]+dp[k+1][j]+w<dp[i][j]) {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+w;
                    s[i][j]=k;
                }
            }
             
        }
    }
    cout<<dp[1][n];
    return 0;
}
