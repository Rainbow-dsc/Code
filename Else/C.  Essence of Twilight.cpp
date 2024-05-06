#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int T,o,ans=0;
int a[maxn],b[maxn],c[maxn];
inline void msort(int l, int r) { 
	int mid=(l+r)/2;
	if(l==r)  return ; 
	else {
		msort(l, mid);
		msort(mid+1,r);
	}
	int i=l;
	int j=mid+1;
	int t=l;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			ans+=mid-i+1;
			b[t++]=a[j];
			++j;
		} else {
			b[t++]=a[i];
			++i;
		}
	}
	while(i<=mid) { 
		b[t++]=a[i];
		++i;
	}
	while(j<=r) {
		b[t++]=a[j];
		++j;
	}
	for(register int i=l;i<=r;++i) a[i]=b[i];
	return;
}
signed main() {
	freopen("essenceoftwilight.in","r",stdin);	
	freopen("essenceoftwilight.out","w",stdout);
	scanf("%lld %lld",&T,&o);
	while(T--) {
		int n,anss=1e18;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int oi=1;oi<=n;oi++) c[oi]=a[oi];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				swap(c[i],c[j]);
				ans=0;
				for(int oi=1;oi<=n;oi++) a[oi]=c[oi];
				msort(1,n);
				anss=min(anss,ans);
				swap(c[i],c[j]);
			}
		}
		printf("%lld\n",anss);
	}
	return 0;
}
