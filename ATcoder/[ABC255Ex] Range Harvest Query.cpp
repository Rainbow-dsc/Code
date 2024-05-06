#include<bits/stdc++.h>
#define int long long
#define maxn 300005
#define mod 998244353
using namespace std;
int m,n,q;
int a[maxn];
struct Node{
	int l,r; mutable int v;
	Node(int l=0,int r=0,int v=0) : l(l),r(r),v(v) {};
	bool operator < (const Node &x) const{ return l<x.l; }
}node; set<Node>s;
auto split(int x) {
	auto it=s.lower_bound(Node(x));
	if(it!=s.end()&&it->l==x) return it; it--;
	if(it->r<x) return s.end();
	node.l=it->l,node.r=it->r,node.v=it->v;
	s.erase(it);s.insert(Node{node.l,x-1,node.v});
	it=s.insert(Node{x,node.r,node.v}).first;
	return it;
}
int assign(int l,int r,int d) {
	auto to=split(r+1),fm=split(l);
	int ans=0;
	for(auto it=fm;it!=to;it++) {
		ans+=(d-it->v)%mod*((it->l+it->r)%mod)%mod*((it->r-it->l+1)%mod)%mod*499122177%mod;
		ans%=mod;
	}
	s.erase(fm,to),s.insert(Node{l,r,d});
	return ans;
}
signed main(){
	scanf("%lld %lld",&n,&q);
	s.insert(Node{1,n,0});
	while(q--) {
		int l,r,d;
		scanf("%lld %lld %lld",&d,&l,&r);
		printf("%lld\n",assign(l,r,d));
	}
	return 0;
}

