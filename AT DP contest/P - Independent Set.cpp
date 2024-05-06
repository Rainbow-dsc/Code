#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
#define mod (int)(1e9+7)
using namespace std;
int n;
bool vis[maxn];
vector<int> P[maxn];
int dp[maxn][2];
void dfs(int x) {
    dp[x][0]=dp[x][1]=1;
    for(auto now:P[x]) {
        if(!vis[now]) {
            vis[now]=true,dfs(now);
            dp[x][0]*=dp[now][0]+dp[now][1],dp[x][0]%=mod;
            dp[x][1]*=dp[now][0],dp[x][1]%=mod;
        }
    }
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        P[x].push_back(y);  
        P[y].push_back(x); 
    }
    vis[1]=true,dfs(1);
    printf("%lld",(dp[1][1]+dp[1][0])%mod);
    return 0;
}