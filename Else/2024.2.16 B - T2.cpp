#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int dp[maxn], a[maxn], na[maxn];
signed main(){
	while(1) {
		int n,m,ans=0,cnt=0;
		scanf("%d %d",&n,&m);
		if(n==0&&m==0) return 0;		
		for(int i=1;i<=m;i++) dp[i]=0;
		dp[0]=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) {
			int x,k=1;
			scanf("%d",&x);
			while(x>=k) {
				na[++cnt] = a[i]*k;
				x-=k,k*=2;
			}
			if(x>0) na[++cnt] = a[i]*x; 
		}
		for(int i=1;i<=cnt;i++) for(int j=m;j>=na[i];j--) dp[j]=max(dp[j],dp[j-na[i]]);
		for(int i=1;i<=m;i++) if(dp[i]>0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
