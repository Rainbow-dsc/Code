#include<bits/stdc++.h>
#define int long long
#define maxn 100005
#define mod (int)(1e9+7)
using namespace std;
int n,k;
int a[maxn],dp[maxn];
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    dp[0]=0;
    for(int i=1;i<=k;i++) {
        dp[i]=0;
        for(int j=1;j<=n;j++) {
            if(i>=a[j]&&dp[i-a[j]]==false) dp[i]=1;
        }
    }
    if(dp[k]==1)printf("First");
    else printf("Second");
    return 0;
}