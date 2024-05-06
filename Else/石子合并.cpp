#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,a[100001],dp[1001][1001],sum[1001];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int v=2;v<=n;v++){
		for(int i=1;i<=n-v+1;i++){
			int j=i+v-1;
			int tmp=sum[j]-sum[i-1];
			dp[i][j]=inf;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+tmp);
			}
		}
	}
	cout<<dp[1][n];
    return 0;
}
