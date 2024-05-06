#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n,m,k;
string s1,s2;
int dp[1001][1001]={1};
int sum[1001][1001];
signed main() {
	scanf("%lld %lld %lld",&n,&m,&k);
	cin>>s1>>s2;
	for(int i=1; i<=n; i++) {
		for(int j=m; j>=1; j--) {
			for(int kk=k; kk>=1; kk--) {
				if(s1[i-1]!=s2[j-1]) sum[j][kk]=0;
				else sum[j][kk]=(sum[j-1][kk]+dp[j-1][kk-1])%mod;
				dp[j][kk]=(dp[j][kk]+sum[j][kk])%mod;
			}
		}
	}
	printf("%lld",dp[m][k]);
	return 0;
}
