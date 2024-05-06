#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m,ans;
int dp[maxn];
vector <int> P[maxn];
void dfs(int x) {
    if(dp[x]!=0) return ; 
    dp[x]=-1;
    for(auto now:P[x]) {
        dfs(now);
        dp[x]=max(dp[now],dp[x]);
    } ++dp[x];
    ans=max(ans,dp[x]);
}
signed main(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=m;i++) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        P[x].push_back(y);
    }
    for(int i=1;i<=n;i++) dfs(i);
    printf("%lld",ans);
    return 0;
}