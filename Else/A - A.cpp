#include<bits/stdc++.h>
#define int long long
#define maxn 2050
using namespace std;
int n;
int a[maxn],b[maxn];
signed main() {
	while(1) {
		scanf("%lld",&n);
		if(n==0) return 0;
		for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
		for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		int ans=0,la=1,lb=1,ra=n,rb=n;
		for(int i=1; i<=n; i++) {
			if (a[ra]>b[rb]) ans+=200,--ra,--rb;
			else if (a[ra]<b[rb]) ans-=200,++la,--rb;
			else if (a[la]>b[lb]) ans+=200,++la,++lb;
			else {
				if (a[la]<b[rb]) ans-=200;
				++la,--rb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
