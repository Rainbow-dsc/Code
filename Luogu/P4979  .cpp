#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,k;
string a;
struct Node {
	int l,r;
	mutable int x;
	Node(int l=0,int r=0,int x=0) : l(l),r(r),x(x) {}
	bool operator < (const Node &p) const { return l<p.l; }
} node;
set<Node>s;
auto split(int x) {
	auto it=s.lower_bound(Node(x));
	if(it!=s.end()&&it->l==x) return it; it--;
	if(it->r<x) return s.end();
	node.l=it->l,node.r=it->r,node.x=it->x;
	s.erase(it),s.insert(Node{node.l,x-1,node.x});
	it=s.insert(Node {x,node.r,node.x}).first;
	return it;
}//bz
void assign(int l,int r,int x) {
	auto to=split(r+1),it=split(l);
	s.erase(it,to),s.insert(Node {l,r,x});
	return ;
}//bz
inline bool query(int l,int r) {
	auto to=split(r+1),fm=split(l);
	bool res=0;
	for(auto it=fm; it!=to; it++) {
		if(it->x!=fm->x) {
			it--;
			assign(fm->l,it->r,fm->x);
			return 0;
		}
	}
	if(fm==s.begin()||to==s.end()) res=1;
	else {
		auto pre=fm;
		pre--;
		if(pre->x==to->x) res=0;
		else res=1;
	}
	assign(l,r,fm->x);
	return res;
}
signed main() {
	scanf("%lld",&n);
	cin>>a;
	node.l=node.r=1,node.x=a[0]-'A';
	for(int i=1;i<n;i++) {
		if(a[i]-'A'!=node.x) {
			node.r=i,s.insert(node);
			node.l=i+1,node.x=a[i]-'A';
		}
	}
	node.r=n,s.insert(node);
	scanf("%lld",&k);
	while(k--) {
		char opt,op;
		int x,y;
		cin>>opt;
		if(opt=='B') {
			scanf("%lld %lld",&x,&y);
			if(query(x,y)) printf("Yes\n");
			else printf("No\n");
		}
		if(opt=='A') {
			scanf("%lld %lld %c",&x,&y,&op);
			assign(x,y,op-'A');
		}
	}
	return 0;
}
