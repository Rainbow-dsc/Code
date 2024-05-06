#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,p,ans=-1e9;
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a);
		if(i==1) p=a;
		else p=max(a,a+p);
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}

