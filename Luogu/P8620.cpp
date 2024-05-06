#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum[1000001],ans=0;
struct p {
	int h,v;
} a[1000001];
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) scanf("%lld%lld",&a[i].h,&a[i].v);
	for(int i=1; i<=n; i++) {
		for(int j=i-1; j>=1; j--)
			if(a[j].h>a[i].h) {
				sum[j]+=a[i].v;
				break;
			}
		for(int j=i; j<=n; j++)
			if(a[j].h>a[i].h) {
				sum[j]+=a[i].v;
				break;
			}
	}
	for(int i=1; i<=n; i++) ans=max(ans,sum[i]);
	cout<<ans;
	return 0;
}
