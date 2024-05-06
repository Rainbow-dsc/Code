#include<bits/stdc++.h>
#define int long long
#define Maxn (int)1e5 + 4
#define inf (int)2e9
#define L fa << 1
#define R fa << 1 | 1
#define mid (l+r >> 1)
using namespace std;

struct t {
	bool neg,posi,zero;
	int maxn,minn,maxneg,minnposi;
};
t a[Maxn << 2],b[Maxn << 2];

int A[Maxn],B[Maxn];
t merge(t a,t b) {
	return (t) {
		a.neg|b.neg, a.posi|b.posi, a.zero|b.zero,
		max(a.maxn,b.maxn), min(a.minn,b.minn), max(a.maxneg,b.maxneg), min(a.minnposi,b.minnposi)
	};
}
void build_a(int fa,int l,int r) {
	a[fa].maxneg = -inf, a[fa].minnposi = inf;
	if(l == r) {
		if(A[l] < 0) {
			a[fa].neg = 1;
			a[fa].maxneg = A[l];
		}
		if(A[l] == 0) a[fa].zero = 1;
		if(A[l] > 0) {
			a[fa].posi = 1;
			a[fa].minnposi = A[l];
		}
		a[fa].maxn = a[fa].minn = A[l];
		return ;
	}
	build_a(L,l,mid), build_a(R,mid+1,r);
	a[fa] = merge(a[L],a[R]);
}
void build_b(int fa,int l,int r) {
	b[fa].maxneg = -inf, b[fa].minnposi = inf;
	if(l == r) {
		if(B[l] < 0) {
			b[fa].neg = 1;
			b[fa].maxneg = B[l];
		}
		if(B[l] == 0) b[fa].zero = 1;
		if(B[l] > 0) {
			b[fa].posi = 1;
			b[fa].minnposi = B[l];
		}
		b[fa].maxn = b[fa].minn = B[l];
		return ;
	}
	build_b(L,l,mid), build_b(R,mid+1,r);
	b[fa] = merge(b[L],b[R]);
}
t query_a(int fa,int l,int r,int ql,int qr) {
	if(ql <= l && r <= qr) return a[fa];

	if(qr <= mid) return query_a(L,l,mid,ql,qr);
	else if(ql > mid) return query_a(R,mid+1,r,ql,qr);
	else {
		t res;
		t ls = query_a(L,l,mid,ql,qr);
		t rs = query_a(R,mid+1,r,ql,qr);
		res = merge(ls,rs);
		return res;
	}
}
t query_b(int fa,int l,int r,int ql,int qr) {
	if(ql <= l && r <= qr) return b[fa];

	if(qr <= mid) return query_b(L,l,mid,ql,qr);
	else if(ql > mid) return query_b(R,mid+1,r,ql,qr);
	else {
		t res;
		t ls = query_b(L,l,mid,ql,qr);
		t rs = query_b(R,mid+1,r,ql,qr);
		res = merge(ls,rs);
		return res;
	}
}

int judge(t a,t b) {

	int res;
	if(a.posi && !(a.neg | a.zero)) {
		if(b.neg) res = a.minn * b.minn;
		else res = a.maxn * b.minn;
	} else if(a.neg && !(a.posi | a.zero)) {
		if(b.posi) res = a.maxn * b.maxn;
		else res = a.minn * b.maxn;
	} else if(a.zero && !(a.posi | a.neg)) {
		res = 0;
	} else if(a.posi && a.zero && !a.neg) {
		if(b.posi && !(b.neg | b.zero)) res = a.maxn * b.minn;
		else res = 0;//
	} else if(a.neg && a.posi && !a.zero) {
		if(b.posi && !(b.neg | b.zero)) res = a.maxn * b.minn;
		else if(!b.zero) {
			if(b.posi) {
				res = max(a.minnposi*b.minn, a.maxneg*b.maxn);
			} else res = a.minn*b.maxn;
		} else res = max(a.minnposi*b.minn, a.maxneg*b.maxn);
	} else if(a.neg && a.zero && !a.posi) {
		if(b.neg && !(b.posi | b.zero)) res = a.minn*b.maxn;
		else res = 0;
	} else if(a.neg && a.zero && a.posi) {
		if(b.posi && !(b.neg | b.zero)) {
			res = a.maxn*b.minn;
		} else if(b.neg && !(b.posi | b.zero)) {
			res = a.minn*b.maxn;
		} else res = 0;
	}
	return res;
}
signed main() {

	int n,m,q;
	scanf("%lld %lld %lld",&n,&m,&q);
	for(int i = 1; i <= n; i ++) scanf("%lld",&A[i]);
	for(int i = 1; i <= m; i ++) scanf("%lld",&B[i]);
	build_a(1,1,n), build_b(1,1,m);

	for(int i = 1; i <= q; i ++) {
		int l1,r1,l2,r2;
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		t a = query_a(1,1,n,l1,r1);
		t b = query_b(1,1,m,l2,r2);
		printf("%lld\n",judge(a,b));
	}
	return 0;
}
