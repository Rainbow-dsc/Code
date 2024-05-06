#include<bits/stdc++.h>
#define int long long
#define maxn 200
using namespace std;
int d,n;
int sum[maxn][maxn];
signed main(){
	scanf("%lld%lld",&d,&n);
	for(int i=1;i<=n;i++) {
		int x,y,k;
		scanf("%lld%lld%lld",&x,&y,&k);
		sum[x+30][y+30]+=k;
	}	
	int ans=0,cnt=0;
	for(int i=1;i<=178;i++) for(int j=1;j<=178;j++) sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	for(int i=30;i<=158;i++) {
		for(int j=30;j<=158;j++) {
			int now=sum[i+d][j+d]-sum[i+d][j-d-1]-sum[i-d-1][j+d]+sum[i-d-1][j-d-1];
			if(now>ans) ans=now,cnt=1;
			else if(ans==now) cnt++;
		}
	}
	printf("%lld %lld",cnt,ans);
	return 0;
}

