#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,q,ans;
struct Node {
	int l,r;
	mutable int v;
	Node(int l=0,int r=0,int v=0):l(l),r(r),v(v) {}
	bool operator < (const Node &rhs) const { return l<rhs.l; }
} node;
set<Node>s;
inline auto split(int x) {
	auto it=s.lower_bound(Node(x));
	if(it!=s.end()&&it->l==x) return it; it--;
	if(it->r<x) return s.end();
	node.l=it->l,node.r=it->r,node.v=it->v;
	s.erase(it);
	s.insert(Node {node.l,x-1,node.v});
	it=s.insert(Node {x,node.r,node.v}).first;
	return it;
}
inline void assign(int l,int r,int v) {
	auto to=split(r+1),fm=split(l);
	for(auto it=fm; it!=to; it++) ans-=(it->r-it->l+1)*(it->v);
	s.erase(fm,to);
	s.insert(Node {l,r,v});
	ans+=(r-l+1)*v;
	return;
}
signed main() {
	scanf("%lld %lld",&n,&q);
	ans=n;
	s.insert(Node{1,n,1});
	while(q--) {
		int opt,l,r;
		scanf("%lld %lld %lld",&l,&r,&opt);
		assign(l,r,opt-1);
		printf("%lld\n",ans);
	}
	return 0;
}
