#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n;
struct va{int a,b,c;}aa[maxn];
int dp[maxn][3];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&aa[i].a,&aa[i].b,&aa[i].c);
    for(int i=1;i<=n;i++) {
        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+aa[i].a;
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+aa[i].b;
        dp[i][3]=max(dp[i-1][1],dp[i-1][2])+aa[i].c;
    }
    printf("%lld",max(dp[n][1],max(dp[n][2],dp[n][3])));
    return 0;
}