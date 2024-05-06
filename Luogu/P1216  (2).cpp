#include<bits/stdc++.h>
using namespace std;
int r,a[1005][1005];
int dp[1005][1005];
int main(){
//	memset(dp,-1,sizeof(dp));
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=r;i>=1;i--)
		for(int j=1;j<=r;j++)
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
	cout<<dp[1][1];
	return 0;
}
