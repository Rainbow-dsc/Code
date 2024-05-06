#include<bits/stdc++.h>
#define int long long
#define maxn 1000000+7
#define lc rt << 1
#define rc rt << 1 | 1
using namespace std;
int n,m,a[maxn],sum[maxn*4],tag[maxn<<2];
void pushup(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt) {
	if(l==r) {
		sum[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}
void pushdown(int rt, int l, int r) {
	if(tag[rt]) {
		int mid(l + r >> 1);
		sum[lc] += tag[rt] * (mid - l + 1);
		sum[rc] += tag[rt] * (r - mid);
		tag[lc] += tag[rt], tag[rc] += tag[rt];
		tag[rt] = 0;
	}
}
void update(int v, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] += v * (r - l + 1);
		tag[rt] += v;
		return ;
	}
	pushdown(rt, l, r);
	int mid=(l+r)>>1;
	if(L<=mid) update(v,L,R,l,mid,rt<<1);
	if(R>mid)  update(v,L,R,mid+1,r,rt<<1|1);
	pushup(rt);
}
int  Query(int L,int R,int l,int r,int rt) {
	if(L<=l&&r<=R) return sum[rt];
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	int ANS=0;
	if(L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
	if(R>mid)  ANS+=Query(L,R,mid+1,r,rt<<1|1);
	return ANS;
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	build(1,n,1);
	for(int i=1; i<=m; i++) {
		int a;
		scanf("%lld",&a);
		if(a==1) {
			int x,z;
			scanf("%lld%lld",&x,&z);
			update(z,x,x,1,n,1);
		} else {
			int x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",Query(x,y,1,n,1));
		}
	}
	return 0;
}
