#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int l,n,m;
int a[maxn];
bool check(int x) {
	int cnt=0,lst=0;
	for(int i=1;i<=n+1;i++) {
		if(a[i]-lst<x) cnt++;
		else lst=a[i];
	}
	return cnt<=m;
}
signed main(){
	scanf("%lld%lld%lld",&l,&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	a[n+1]=l;
	int left=1,right=l,ans;
	while(left<=right) {
		int mid=(left+right)>>1;
		if(check(mid)) {
			ans=mid;
			left=mid+1;
		} else right=mid-1;
	}
	printf("%lld",ans);
	return 0;
}

