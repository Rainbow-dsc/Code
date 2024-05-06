#include<bits/stdc++.h>
#define int long long
#define maxn 40004
using namespace std;
int n,cnt=0;
int vis[maxn],prime[maxn];
double ln[maxn],dp[maxn];
void get_prime(int n) {
	for(int i=2; i<=n; i++) {
		if(vis[i]==0) prime[++cnt]=i,ln[cnt]=log(i);
		for(int j=1; prime[j]*i<=n&&j<=cnt; j++) {
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
signed main() {
	freopen("icecream.in","r",stdin);
	freopen("icecream.out","w",stdout);
	scanf("%lld",&n);
	get_prime(n);
	for(int i=1; i<=cnt; i++) {
		for(int j=n; j>=prime[i]; j--) {
			int pp=prime[i],k=1;
			while(pp<=j) {
				dp[j]=max(dp[j-pp]+ln[i]*k,dp[j]);
				pp*=prime[i]; k++;
			}
		}
	}
	printf("%.7lf", dp[n]);
	return 0;
}
