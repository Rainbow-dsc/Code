#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int a[201];
signed main() {
	scanf("%lld",&t);
	while(t--) {
		int n,k,x;
		scanf("%lld%lld%lld",&n,&k,&x);
		if(x+1<k||n<k) printf("-1\n");
		else {
			int sum=(k-1)*k/2;
			int cnt=n-k;
			int ans=sum+cnt*x;
			if(k==x) {
				printf("%lld\n",ans-cnt);
			}
			else printf("%lld\n",ans);
		}
	}
	return 0;
}

