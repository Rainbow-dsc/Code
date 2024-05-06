#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,m,Ans,pa=1,pc=0;
int a[maxn],b[maxn],c[maxn],ans[maxn];
bool cmp(int x,int y) {
	return x>y;
}
signed main() {
//	freopen("coin.in","r",stdin);
//	freopen("coin.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	for(int i=0; i<n; i++) {
		scanf("%lld",&b[i]);
		c[i]=a[i]+b[i];
	}
	sort(a,a+n,cmp),sort(c,c+n,cmp);
	ans[1]=a[0];
	for(int i=3; i<=m; i+=2) {
		ans[i]=ans[i-2];
		ans[i]+=a[pa]+a[pa+1];
		pa+=2;
		while(pa>1&&pc<n&&a[pa-2]+a[pa-1]<c[pc]) {
			ans[i]-=a[pa-2]+a[pa-1];
			ans[i]+=c[pc];
			pa-=2;
			pc++;
		}
	}
	pa=0,pc=0;
	for(int i=2; i<=m; i+=2) {
		ans[i]=ans[i-2];
		ans[i]+=a[pa]+a[pa+1];
		pa+=2;
		while(pa>1 && pc<n && a[pa-2]+a[pa-1]<c[pc]) {
			ans[i]-=a[pa-2]+a[pa-1];
			ans[i]+=c[pc];
			pa-=2;
			pc++;
		}
	}
	for(int i=1;i<=m;i++) Ans^=ans[i];
	printf("%lld",Ans);
	return 0;
}
