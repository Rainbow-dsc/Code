#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T& x) {
	x=0;T f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=x*f;
	return;
}
template <typename T,typename ...Arg>void read(T& x,Arg& ...arg){
	read(x);
	read(arg...);
}
template <typename T>void write(T x) {
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
template <typename T,typename ...Arg>void write(T& x,Arg& ...arg){
	write(x);
	putchar(' ');
	write(arg...);
}
#define MAXN 500005
int n,m,l,r;
string v;
namespace ChthollyTree{
	struct Node{
		int l,r;
		mutable int v;
		Node(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
		bool operator < (const Node &rhs) const {return l<rhs.l;}
	}node;
	set<Node>s;
	inline set<Node>::iterator split(int x){
		set<Node>::iterator it=s.lower_bound(Node(x));
		if(it!=s.end()&&it->l==x) return it;
		it--;
		if(it->r<x) return s.end();
		node.l=it->l,node.r=it->r,node.v=it->v;
		s.erase(it);
		s.insert(Node{node.l,x-1,node.v});
		it=s.insert(Node{x,node.r,node.v}).first;
		return it;
	}//çæ¶äÀòÊ÷-·ÖÁÑ²Ù×÷
	inline void assign(int l,int r,int v){
		set<Node>::iterator to=split(r+1),it=split(l);
		s.erase(it,to);
		s.insert(Node{l,r,v});
		return;
	}//çæ¶äÀòÊ÷-ÍÆÆ½²Ù×÷/Çø¼äĞŞ¸Ä²Ù×÷
	inline bool query(int l,int r){
		set<Node>::iterator to=split(r+1),fm=split(l);
		bool res=0;
		for(set<Node>::iterator it=fm;it!=to;it++){
			if(it->v!=fm->v){
				it--;
				assign(fm->l,it->r,fm->v);
				return 0;
			}
		}
		if(fm==s.begin()||to==s.end()) res=1;
		else{
			set<Node>::iterator pre=fm;
			pre--;
			if(pre->v==to->v) res=0;
			else res=1;	
		}
		assign(l,r,fm->v);
		return res;
	}
}//çæ¶äÀòÊ÷
using namespace ChthollyTree;
signed main(){
	read(n);
	string a;
	cin>>a;
	node.l=node.r=1;
	node.v=a[0]-'A';
	for(int i=1;i<n;i++){
		if(a[i]-'A'!=node.v){
			node.r=i;
			s.insert(node);
			node.l=i+1;
			node.v=a[i]-'A';
		}
	}
	node.r=n;
	s.insert(node);
	read(m);
	while(m--){
		string opt;
		cin>>opt;
		if(opt[0]=='B'){
			read(l,r);
			if(query(l,r)) printf("Yes\n");
			else printf("No\n");
		}
		else{
			read(l,r);
			cin>>v;
			assign(l,r,v[0]-'A');
		}
	}
	return 0;
}
