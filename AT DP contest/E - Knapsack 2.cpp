#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,w,sum;
struct aa{int w,v;}a[maxn];
int dp[maxn];
signed main(){
    scanf("%lld %lld",&n,&w);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld",&a[i].w,&a[i].v);
        sum+=a[i].v;
    }
    for(int i=1;i<=sum;i++) dp[i]=1e18;
    for(int i=1;i<=n;i++) for(int j=sum;j>=a[i].v;j--) dp[j]=min(dp[j],dp[j-a[i].v]+a[i].w);
    for(int i=sum;i>=0;i--) if(dp[i]<=w) {printf("%lld",i);return 0;}
    return 0;
}