#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000001];
int dp[100001];
int main(){
	memset(dp,0x3f3f3f,sizeof(dp));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[1]=0;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=k;j++)
			dp[i+j]=min(dp[i+j],dp[i]+abs(a[i]-a[j+i]));
	cout<<dp[n];
	return 0;
}
