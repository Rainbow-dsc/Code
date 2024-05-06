#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,mod=1,x,ans;
int p[20][maxn];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&x); mod=10;
		for(int k=1;k<=16;k++) p[k][i]=x%mod,mod*=10;
		while(x) ans+=n*2*(x%10),x/=10;
	} mod=1;
	for(int i=1;i<=16;i++) {
		mod*=10;
		sort(p[i]+1,p[i]+1+n);
		for(int j=1;j<=n;j++) ans-=9*(p[i]+n+1-lower_bound(p[i]+1,p[i]+n+1,mod-p[i][j]));
	}
	printf("%lld",ans);
	return 0;
}
