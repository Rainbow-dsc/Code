#include<bits/stdc++.h>
using namespace std;
int y,z,dp[50005][505];
signed main(){
	scanf("%d%d",&y,&z);
	dp[0][0]=1;
	for(int i=0;i<=y;i++)
		for(int j=0;j<z;j++)
			for(int k=1;k<=9;k++){
				dp[i+k][(10*j+k)%z]+=dp[i][j];
				dp[i+k][(10*j+k)%z]%=1000000007;
			}
	cout<<dp[y][0];
	return 0;
}
