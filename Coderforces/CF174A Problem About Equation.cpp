#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,b,maxn=-1e18,minn=1e18;
int a[105];
double d[105];
signed main() {
	scanf("%lld%lld",&n,&b);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	for(int i=1;i<=n;i++) {
		d[i]=maxn-a[i];
		b-=d[i];
		a[i]+=d[i];
	}
	if(b<0) {
		cout<<-1;
		return 0;
	}
	double sheng=b*1.0/n*1.0;
	for(int i=1;i<=n;i++) d[i]+=sheng;
	for(int i=1;i<=n;i++) {
		printf("%.6lf\n",d[i]);
	} 
	return 0;
}

