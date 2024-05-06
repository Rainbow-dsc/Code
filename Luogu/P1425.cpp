#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,h[60],dp[60];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++) dp[i]=1e8;
	if(h[2]-h[1]>1){
		cout<<-1;
		return 0;
	}
	dp[1]=0;
	for(int i=1;i<=n;i++){
		if(h[i]-h[i-1]==1) dp[i]=min(dp[i],dp[i-1]+1);
		for(int j=i-1;j>=1;j--)
			for(int k=i+1;k<=n;k++)
				if(h[k]-h[j]<=pow(2,i-j)) dp[k]=min(dp[k],dp[i]+i-j+1);
	}
	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	cout<<endl; 
	if(dp[n]!=1e8) 
		cout<<dp[n];
	else cout<<-1;
	return 0;
}
