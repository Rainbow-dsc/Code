#include<bits/stdc++.h>
using namespace std;
int n,a[100001],dp[1001][1001];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int v=3;v<=n+1;v++){
		for(int i=1;i+v-1<=2*n;i++){
			int j=i+v-1;
			for(int k=i+1;k<j;k++){
				dp[i][j]=max(dp[i][j],a[i]*a[j]*a[k]+dp[i][k]+dp[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][n+i]);
	cout<<ans;
    return 0;
}
