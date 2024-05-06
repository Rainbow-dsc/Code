#include<bits/stdc++.h>
#define int long long
#define maxn 400005
using namespace std;
int n;
struct aa{ int x,y; }a[maxn],tp[maxn];
bool cmp1(aa x,aa y) { return x.x<y.x; }
bool cmp2(aa x,aa y) { return x.y<y.y; }
int  p(int x) { return x*x; }
int  calc(aa x,aa y) { return p(x.x-y.x)+p(x.y-y.y); }
int solve(int l,int r) {
	if(l>=r) return 1e18+4;
	if(r-l==1) return calc(a[l],a[r]);
	int mid=(l+r)>>1,cnt=0;
	int ans=min(solve(l,mid),solve(mid,r));
	for(int i=l;i<=r;i++) if(p(a[i].x-a[mid].x)<ans) tp[++cnt]=a[i];
	sort(tp+1,tp+cnt+1,cmp2);
	for(int i=1;i<=cnt;i++) for(int j=i+1;j<=cnt&&p(tp[i].y-tp[j].y)<ans;j++) ans=min(ans,calc(tp[i],tp[j]));
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp1);
	printf("%lld",solve(1,n));
	return 0;
}
