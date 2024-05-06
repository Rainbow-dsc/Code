#include <bits/stdc++.h>
#define int long long
#define maxn 1007
using namespace std;
int n;
int b[maxn],cnt=1;
int dp[maxn];
void prime(){
	for(int i=2;i<=500;i++) if(!b[i]) for(int j=2;i*j<=1000;j++) b[i*j]=1;
}
signed main() {
	prime();
	scanf("%lld",&n);
	dp[0]=1;
	for(int i=2;i<=n;i++) if(!b[i]) for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
	printf("%lld",dp[n]);
	return 0;
}

