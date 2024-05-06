#include<bits/stdc++.h>
using namespace std;
int n,wl,wr;
struct aa{
	int l,r;
	int sumq;
}a[100001];
bool cmp(aa x,aa y){
	if(x.sumq!=y.sumq) return x.sumq<y.sumq;
	else return x.r>y.r;
}
signed main(){
	scanf("%lld",&n);
	scanf("%lld%lld",&wl,&wr);
	a[0].sumq=wl;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].l,&a[i].r);
		a[i].sumq=a[i].l*a[i-1].sumq;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,a[i].sumq/a[i].r);
	cout<<ans;
	return 0;
}
