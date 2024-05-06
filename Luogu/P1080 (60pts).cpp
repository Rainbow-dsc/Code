#include<bits/stdc++.h>]
#define int long long
using namespace std;
int n,p,c;
struct aa {
	int x,y,r,q;
} a[100001];
bool cmp(aa e,aa f) {
	return e.r<f.r;
}
signed main() {
	scanf("%lld",&n);
	scanf("%lld%lld",&p,&c);
	a[0].r=p*c;
	a[0].q=p;
	for(int i=1; i<=n; i++) {
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].r=a[i].x*a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) a[i].q=a[i-1].q*a[i].x;
	int ans=0;
	for(int i=1; i<=n; i++) ans=max(ans,int(a[i-1].q/a[i].y));
	cout<<ans;
	return 0;
}
