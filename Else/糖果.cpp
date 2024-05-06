#include<bits/stdc++.h>
using namespace std;
const int inf=int(1e20);
int n,a[10000001],dp[3005][3005],sum[3005],k;
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int v=2;v<=n;v++){
		for(int i=1;i<=n-v+1;i++){
			int j=i+v-1;
			int tmp=pow(sum[j]-sum[i-1],k);
			dp[i][j]=inf;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+tmp);
			}
		}
	}
	printf("%d",dp[1][n]);
    return 0;
}
