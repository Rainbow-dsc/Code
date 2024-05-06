#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m,sed,vm,a[maxn],mod=1000000007;
struct Mag {
	int op,l,r,x,y;
} mag[maxn];
struct Node {
	int l,r;
	mutable int v;
	Node(int l=0,int r=0,int v=0):l(l),r(r),v(v) {}
	bool operator < (const Node &rhs) const {
		return l<rhs.l;
	}
} node;
struct RankList {
	int l,r,v;
//	RankList(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
	bool operator < (const RankList &rhs) const {
		return v<rhs.v;
	}
} rkl;
set<Node> s;
inline int quick_pow(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
namespace data_produce {
	inline int rnd() {
		int ret=sed;
		sed=(sed*7+13)%1000000007;
		return ret;
	}
	inline void data() {
		for(int i=1; i<=n; i++) a[i]=(rnd()%vm)+1;
		for(int i=1; i<=m; i++) {
			mag[i].op=(rnd()%4)+1;
			mag[i].l=(rnd()%n)+1;
			mag[i].r=(rnd()%n)+1;
			if(mag[i].l>mag[i].r) swap(mag[i].l,mag[i].r);
			if(mag[i].op==3) mag[i].x=(rnd()%(mag[i].r-mag[i].l+1))+1;
			else mag[i].x=(rnd()%vm)+1;
			if(mag[i].op==4) mag[i].y=(rnd()%vm)+1;
		}
		return;
	}
}
using namespace data_produce;
namespace CT {
	inline set<Node>::iterator split(int x) {
		set<Node>::iterator it=s.lower_bound(Node(x));
		if(it!=s.end()&&it->l==x) return it;
		it--;
		if(it->r<x) return s.end();
		node.l=it->l,node.r=it->r,node.v=it->v;
		s.erase(it);
		s.insert(Node {node.l,x-1,node.v});
		it=s.insert(Node {x,node.r,node.v}).first;
		return it;
	}
	inline void assign(int l,int r,int v) {
		set<Node>::iterator to=split(r+1),it=split(l);
		s.erase(it,to);
		s.insert(Node {l,r,v});
		return;
	}
	inline void add(int l,int r,int v) {
		set<Node>::iterator to=split(r+1),it=split(l);
		for(; it!=to; it++) it->v+=v;
		return;
	}
	inline int rank_search(int l,int r,int x) {
		set<Node>::iterator to=split(r+1),it=split(l);
		vector<RankList>v;
		v.clear();
		for(; it!=to; it++) v.push_back(RankList {it->l,it->r,it->v});
		sort(v.begin(),v.end());
		for(int i=0; i<(int)v.size(); i++) {
			if(v[i].r-v[i].l+1<x) x-=v[i].r-v[i].l+1;
			else return v[i].v;
		}
		return 0;
	}
	inline int query(int l,int r,int x,int y) {
		int res=0;
		mod=y;
		set<Node>::iterator to=split(r+1),it=split(l);
		for(; it!=to; it++) res=(res+(quick_pow(it->v%mod,x)%mod*(it->r-it->l+1)%mod)%mod)%mod;
		return res%mod;
	}
}
using namespace CT;
signed main() {
	scanf("%lld %lld %lld %lld",&n,&m,&sed,&vm);
	data();
	for(int i=1; i<=n; i++) s.insert(Node{i,i,a[i]});
	for(int i=1; i<=m; i++) {
		if(mag[i].op==1) add(mag[i].l,mag[i].r,mag[i].x);
		else if(mag[i].op==2) assign(mag[i].l,mag[i].r,mag[i].x);
		else if(mag[i].op==3) printf("%lld\n",rank_search(mag[i].l,mag[i].r,mag[i].x));
		else printf("%lld\n",query(mag[i].l,mag[i].r,mag[i].x,mag[i].y));
	}
	return 0;
}
