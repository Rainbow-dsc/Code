#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,g;
int a[102];
int z[102];
int dp[102][10004];
signed main() {
	cin>>c>>g;
	for(int i=1; i<=c; i++) cin>>a[i];
	for(int i=1; i<=g; i++) cin>>z[i];
	dp[0][3000]=1;
	for(int i=1; i<=g; i++)
		for(int j=1; j<=c; j++)
			for(int k=-3000; k<=3000; k++)
				dp[i][3000+k+z[i]*a[j]]+=dp[i-1][3000+k];
	cout<<dp[g][3000];
	return 0;
}
