#include<bits/stdc++.h>
#define maxn 1000005
#define int long long
#define lc rt<<1
#define rc rt<<1|1 
using namespace std;
int n,m;
int a[maxn],minn[maxn<<2],tag[maxn<<2]; 
void push_up(int rt) {
	minn[rt]=min(minn[lc],minn[rc]);
}
void build(int rt,int l,int r) {
	int mid=(l+r)>>1;
	if(l==r) {
		minn[rt]=a[l];
		return ;
	} else {
		build(lc,l,mid);
		build(rc,mid+1,r);
		push_up(rt);
	}
}
void push_down(int rt) {
	minn[lc]-=tag[rt];
	minn[rc]-=tag[rt];
	tag[lc]+=tag[rt];
	tag[rc]+=tag[rt];
	tag[rt]=0;
} 
void update(int rt,int l,int r,int L,int R,int rainbow) {
	if(l<=L&&R<=r) {
		minn[rt]-=rainbow;
		tag[rt]+=rainbow;
	} else {
		if(tag[rt]) push_down(rt);
		int mid=(L+R)>>1;
		if(l<=mid) update(lc,l,r,L,mid,rainbow);
		if(r>mid) update(rc,l,r,mid+1,R,rainbow);
		push_up(rt);
	}
}
signed main() {
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++) {
		int d,s,t;
		scanf("%lld %lld %lld",&d,&s,&t);
		update(1,s,t,1,n,d);
		if(minn[1]<0) {
			printf("-1\n%lld",i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
