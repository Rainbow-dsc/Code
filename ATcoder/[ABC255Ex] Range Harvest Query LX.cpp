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
#define MAXN 100005
#define int long long
#define mod 998244353
int n,m,l,r,d;
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
	inline int assign(int l,int r,int d){
		set<Node>::iterator to=split(r+1),fm=split(l);
		int ans=0;
		for(set<Node>::iterator it=fm;it!=to;it++){
			ans+=(d-it->v)%mod*((it->l+it->r)%mod)%mod*((it->r-it->l+1)%mod)%mod*499122177%mod;
			ans%=mod;
		}
		s.erase(fm,to);
		s.insert(Node{l,r,d});
		return ans;
	}//çæ¶äÀòÊ÷-ÍÆÆ½²Ù×÷/Çø¼äĞŞ¸Ä²Ù×÷
}//çæ¶äÀòÊ÷
using namespace ChthollyTree;
signed main(){
	read(n,m);
	s.insert(Node{1,n,0});
	while(m--){
		read(d,l,r);
		write(assign(l,r,d));
		putchar('\n');
	}
	return 0;
}

