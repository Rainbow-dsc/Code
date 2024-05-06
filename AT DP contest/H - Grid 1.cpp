#include<bits/stdc++.h>
#define int long long
#define maxn 1005
#define mod (int)(1e9+7)
using namespace std;
int n,m;
int mp[maxn][maxn],dp[maxn][maxn];
signed main(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char x;cin>>x;
            if(x=='.') mp[i][j]=0;
            else mp[i][j]=1;
        }
    } dp[0][1]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j]==0) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    printf("%lld",dp[n][m]);
    return 0;
}