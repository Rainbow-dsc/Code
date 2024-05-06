#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int t,ans_max,ans_min;
int a[maxn],b[maxn];
signed main() {
	scanf("%lld",&t);
	while(t--) {
		int n,m,bi=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++) scanf("%lld",&b[i]),bi|=b[i];
		if(n%2!=0) {
			ans_min=a[1];
			for(int i=2;i<=n;i++) ans_min^=a[i];
			for(int i=1;i<=n;i++) a[i]|=bi;
			ans_max=a[1];
			for(int i=2;i<=n;i++) ans_max^=a[i];
			printf("%lld %lld\n",ans_min,ans_max);
		}
		if(n%2==0) {
			ans_min=a[1];
			for(int i=2;i<=n;i++) ans_min^=a[i];
			for(int i=1;i<=n;i++) a[i]|=bi;
			ans_max=a[1];
			for(int i=2;i<=n;i++) ans_max^=a[i];
			printf("%lld %lld\n",ans_max,ans_min);
		}
	}
	return 0;
}

