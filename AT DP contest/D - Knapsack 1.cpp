#include<bits/stdc++.h>
#define int long long
#define maxn 105
using namespace std;
int n,W;
struct aa { int w,v; }a[maxn];
int dp[100005];
signed main(){
    scanf("%lld %lld",&n,&W);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].w,&a[i].v);
    for(int i=1;i<=n;i++) for(int j=W;j>=a[i].w;j--) dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
    cout<<dp[W];
    return 0;
}