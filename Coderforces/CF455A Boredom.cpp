#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
int num[10001];
int maxx=0;
int dp[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
		maxx=max(a[i],maxx);
	}
	dp[1]=num[1];
	for(int i=2;i<=n;i++) dp[i]=max(dp[i-1],dp[i-2]+num[i]*i);
	cout<<dp[maxx];
	return 0;
}
