#include<bits/stdc++.h>
#define maxn 1000005
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
//#define mid ((l+r)>>1)
//#define lson rt<<1,l,mid
//#define rson rt<<1|1,mid+1,r
//inline void read(int &x) {
//	char c=getchar();
//	int p=1;
//	x=0;
//	while(!isdigit(c)) {
//		if(c=='-')p=-1;
//		c=getchar();
//	}
//	while(isdigit(c)) {
//		x=(x<<1)+(x<<3)+(c^'0');
//		c=getchar();
//	}
//	x*=p;
//}
int n,m;
int minn[maxn<<2],tag[maxn<<2],a[maxn];
void push_up(int rt) {
//	minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
	minn[rt]=min(minn[lc],minn[rc]);
}
void build(int rt,int l,int r) {
//	if(l==r) read(minn[rt]);
	if(l==r) {
		minn[rt]=a[l];
		return ;
	}
	else {
//		build(lson);
//		build(rson);
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		push_up(rt);
	}
}
void push_down(int rt) {
//	minn[rt<<1]-=tag[rt];
//	minn[rt<<1|1]-=tag[rt];
//	tag[rt<<1]+=tag[rt];
//	tag[rt<<1|1]+=tag[rt];
	minn[lc]-=tag[rt];
	minn[rc]-=tag[rt];
	tag[lc]+=tag[rt];
	tag[rc]+=tag[rt];
	tag[rt]=0;
}
//void update(int rt,int l,int r,int L,int R,int pcr) {
//	if(l>=L&&r<=R) {
//		minn[rt]-=pcr;
//		tag[rt]+=pcr;
//	} else {
//		if(tag[rt])push_down(rt);
//		if(L<=mid) update(lson,L,R,pcr);
//		if(R>mid) update(rson,L,R,pcr);
//		push_up(rt);
//	}
//}
void update(int rt,int l,int r,int L,int R,int pcr) {
	if(l<=L&&R<=r) {
		minn[rt]-=pcr;
		tag[rt]+=pcr;
	} else {
		if(tag[rt]) push_down(rt);
		int mid=(L+R)>>1;
		if(l<=mid) update(lc,l,r,L,mid,pcr);
		if(r>mid)  update(rc,l,r,mid+1,R,pcr);
		push_up(rt);
	}
}
signed main() {
//	read(n);
//	read(m);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++) {
		int d,s,t;
		cin>>d>>s>>t;
//		cout<<i<<endl;
		update(1,s,t,1,n,d);
		if(minn[1]<0) {
			cout<<-1<<endl<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
