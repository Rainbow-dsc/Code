//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define maxn 100005
#define mod (int)(1e8-3)
using namespace std;
int n,ans=0;
int t[maxn],re[maxn],tp[maxn];
struct aa{ int h,id,st; }a[maxn],b[maxn];
bool cmp(aa x,aa y) { return x.h<y.h; }
inline void msort(int l, int r) { 
	int mid=(l+r)/2;
	if(l==r)  return ; 
	else msort(l, mid),msort(mid+1,r);
	int i=l,j=mid+1,cnt=l;
	while(i<=mid&&j<=r) {
		if(t[i]>t[j]) {
			ans+=mid-i+1;
			tp[cnt++]=t[j++];
		} else tp[cnt++]=t[i++];
	}
	while(i<=mid) tp[cnt++]=t[i++];
	while(j<=r) tp[cnt++]=t[j++];
	for(register int i=l;i<=r;++i) t[i]=tp[i];
	return;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].h),a[i].id=i;
	for(int i=1;i<=n;i++) scanf("%lld",&b[i].h),b[i].id=i;
	sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++) a[a[i].id].st=i,b[b[i].id].st=i;
	for(int i=1;i<=n;i++) re[b[i].st]=i;
	for(int i=1;i<=n;i++) t[i]=re[a[i].st];
	msort(1,n);
	printf("%lld",ans%mod);
    return 0;
}
