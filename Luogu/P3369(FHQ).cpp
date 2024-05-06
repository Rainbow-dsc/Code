#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int T,opt,x;
struct FHQ{
	struct Node{int val,rd;}node[maxn];
	int root,siz[maxn],son[maxn][2],cnt=0;
	int rx,ry,rz;
	void update(int rt) {siz[rt]=siz[son[rt][0]]+siz[son[rt][1]]+1; }
	int add(int x) {
		siz[++cnt]=1;
		node[cnt].val=x;
		node[cnt].rd=rand();
		return cnt;
	} 
	void split(int rt,int key,int &x,int &y) {
		if(!rt) return (void)(x=y=0);
		if(node[rt].val<=key) {
			 x=rt;
			 split(son[rt][1],key,son[rt][1],y);
		} else {
			y=rt;
			split(son[rt][0],key,x,son[rt][0]);
		} update(rt);
	}
	void split1(int rt,int sizz,int &x,int &y) {
		if(!rt) return (void)(x=y=0);
		if(siz[son[rt][0]]<sizz) {
			x=rt;
			split(son[rt][1],sizz-(siz[son[rt][0]]+1),son[rt][1],y);
		} else {
			y=rt;
			split(son[rt][0],sizz,x,son[rt][0]);
		} update(rt);
	}
	int merge(int l,int r) {
		if(!l||!r) return l+r;
		if(node[l].rd<node[r].rd) {
			son[l][1]=merge(son[l][1],r);
			update(l);
			return l;
		} else {
			son[r][0]=merge(l,son[r][0]);
			update(r);
			return r;
		}
	}
	int getrank(int x,int k) {
		while(true) {
			if(k<=siz[son[x][0]]) x=son[x][0];
			else if(k>siz[son[x][0]]+1) {
				k-=(siz[son[x][0]]+1);
				x=son[x][1];
			} else return x;
		}
	}
	void insert(int x) {
		split(root,x,rx,ry);
		root=merge(merge(rx,add(x)),ry);
	} 
	void del(int x) {
		split(root,x,rx,rz);
		split(rx,x-1,rx,ry);
		ry=merge(son[ry][0],son[ry][1]);
		root=merge(merge(rx,ry),rz);
	}
	int getpre(int x) {
		int gg;
		split(root,x-1,rx,ry);
		if(!rx) return -1;
		gg=getrank(rx,siz[rx]);
		root=merge(rx,ry);
		return node[gg].val;
	}
	int getnxt(int x) {
		int gg;
		split(root,x,rx,ry);
		if(!ry) return -1;
		gg=getrank(ry,1);
		root=merge(rx,ry);
		return node[gg].val;
	}
	int getnum(int x) {
		int gg;
		split(root,x-1,rx,ry);
		gg=siz[rx]+1;
		root=merge(rx,ry);
		return gg;
	}
	int getrnk(int x) { return node[getrank(root,x)].val;}
}Treap;
signed main(){
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld %lld",&opt,&x);
		if(opt==1) Treap.insert(x);
		if(opt==2) Treap.del(x);
		if(opt==3) cout<<Treap.getnum(x)<<endl;
		if(opt==4) cout<<Treap.getrnk(x)<<endl;
		if(opt==5) cout<<Treap.getpre(x)<<endl;
		if(opt==6) cout<<Treap.getnxt(x)<<endl;
	}
	return 0;
}