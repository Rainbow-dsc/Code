#include<bits/stdc++.h>
#define mod (int)(1e9+7)
#define int long long
#define maxn 100
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int n,k;
int a[maxn][maxn];
int dp[maxn][maxn][maxn+10];//i到j的经历2^k步后的方案数
int g[maxn][maxn];
int logg[maxn];
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
    int cnt=0;
    while(k){
        if(k%2==1) logg[cnt++]=1;
        else cnt++;
        k/=2;
    }
    cnt--;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]==1) dp[i][j][0]=1;
    for(int x=0;x<=cnt;x++)for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j][x+1]+=dp[i][k][x]*dp[k][j][x],dp[i][j][x+1]%=mod;
    for(int i=1;i<=n;i++) g[0][i]=1;
    for(int i=0;i<=cnt;i++) 
    {
        if (logg[i]) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
            g[i+1][k]+=g[i][j]*dp[j][k][i],g[i+1][k]%=mod;
        else for (int j=1;j<=n;j++) g[i+1][j]=g[i][j],g[i+1][j]%=mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=g[cnt+1][i],ans%=mod;
    printf("%lld",ans);
    return 0;
}