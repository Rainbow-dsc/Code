#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define maxn 300005
using namespace std;
struct aa{
	int att,hp;
	int ra,sum;
}a[maxn]; 
struct bb{
	int att,hp;
	int ra;
}b[maxn];
int n,m,v,ans[maxn];
bool js(int k,int M) {
	if(a[k].ra/b[M].att+a[k].sum-a[k].sum/b[M].att>=b[M].hp) return true;
	else return false;
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&v);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i].att,&a[i].hp); 
		a[i].ra+=a[i-1].ra+(a[i].hp)*a[i].att;
		a[i].sum+=a[i].att+a[i-1].sum;
	}
	for(int i=1;i<=m;i++) {
		scanf("%lld%lld",&b[i].att,&b[i].hp);
//		b[i].ra=(b[i].hp+1)*b[i].att;
	}
	for(int M=1;M<=m;M++) {
		int l=1,r=n,k=-1;
		while(l<=r) {
			int mid=(l+r)<<1;
			if (js(mid,M)==true) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
		}
		ans[M]=k;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}

