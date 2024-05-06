#include <bits/stdc++.h>
#define int long long
#define maxn (int)(2e5+7)
using namespace std;
int T;
struct aa {
	int a,b;
} P[maxn];
int sum[maxn];
signed main() {
	scanf("%lld",&T);
	while(T--) {
		int n,m;
		scanf("%lld %lld",&n,&m);
		memset(sum,0,sizeof(sum));
		for(int i=1; i<=n; i++) scanf("%lld",&P[i].a);
		for(int i=1; i<=n; i++) scanf("%lld",&P[i].b);
		for(int i=1; i<=m; i++) sum[i]=sum[i-1]+P[i].b;
		int ans=0,las=0;
		for(int i=m+1; i<=n; i++) ans+=min(P[i].a,P[i].b);
		int cnt=1e9;
		for(int i=m;i>=1;i--) {
			cnt=min(cnt,P[i].a+sum[m]-sum[i]);
		}
		cout<<ans+cnt<<endl;
	}
	return 0;
}
