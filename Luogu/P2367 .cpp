#include <bits/stdc++.h>
#define int long long
#define maxn 5000005
using namespace std;
int n,pp;
int a[maxn],p[maxn],cr[maxn];
signed main() {
	scanf("%lld%lld",&n,&pp);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		p[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=pp;i++) {
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		p[x]+=z;
		p[y+1]-=z;
	}
	int ans=1e18;
	for(int i=1;i<=n;i++) {
		cr[i]=p[i]+cr[i-1];
		ans=min(ans,cr[i]);
	}
	cout<<ans;
//	for(int i=1;i<=n;i++) cout<<cr[i]<<" ";
	return 0;
}

