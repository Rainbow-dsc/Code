#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10000001];
int dp[10000001];
int cost(int i,int j){
	return abs(a[i]-a[j]);
}
signed main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    dp[2]=abs(a[1]-a[2]);
    for(int i=3;i<=n;i++) dp[i]=min(dp[i-1]+cost(i,i-1),dp[i-2]+cost(i,i-2));
    cout<<dp[n]<<endl;
    return 0;
}
