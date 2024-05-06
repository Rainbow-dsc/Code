#include<bits/stdc++.h>
using namespace std;
int T,op,x;
namespace Treap {
	struct node {
		int val,rd;
	} p[100005];
	int root,size[100005],son[100005][2],cnt=0,rx,ry,rz;
	void update(int rt) {
		size[rt]=size[son[rt][0]]+size[son[rt][1]]+1;
	}
	int add(int x) {
		cnt++;
		size[cnt]=1;
		p[cnt].val=x;
		p[cnt].rd=rand();
		return cnt;
	}
	void split(int rt,int key,int &x,int &y) {
		if(!rt) {
			x=y=0;
			return;
		}
		if(p[rt].val<=key) {
			x=rt;
			split(son[rt][1],key,son[rt][1],y);
		} else {
			y=rt;
			split(son[rt][0],key,x,son[rt][0]);
		}
		update(rt);
	}
	void split1(int rt,int siz,int &x,int &y) {
		if(!rt) {
			x=y=0;
			return;
		}
		if(size[son[rt][0]]>=siz) {
			y=rt;
			split1(son[rt][0],siz,x,son[rt][0]);
		} else {
			x=rt;
			split1(son[rt][1],siz-(size[son[rt][0]]+1),son[rt][1],y);
		}
		update(rt);
	}
	int merge(int l,int r) {
		if(!l||!r) return l+r;
		if(p[l].rd<p[r].rd) {
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
			if(k<=size[son[x][0]]) {
				x=son[x][0];
			} else if(k>size[son[x][0]]+1) {
				k-=(size[son[x][0]]+1);
				x=son[x][1];
			} else {
				return x;
			}
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
		gg=getrank(rx,size[rx]);
		root=merge(rx,ry);
		return p[gg].val;
	}
	int getnxt(int x) {
		int gg;
		split(root,x,rx,ry);
		if(!ry) return -1;
		gg=getrank(ry,1);
		root=merge(rx,ry);
		return p[gg].val;
	}
	int getnum(int x) {
		int gg;
		split(root,x-1,rx,ry);
		gg=size[rx]+1;
		root=merge(rx,ry);
		return gg;
	}
	int getrnk(int x) {
		return p[getrank(root,x)].val;
	}
}
using namespace Treap;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>op>>x;
		if(op==1) Treap::insert(x);
		if(op==2) Treap::del(x);
		if(op==3) cout<<Treap::getnum(x)<<endl;
		if(op==4) cout<<Treap::getrnk(x)<<endl;
		if(op==5) cout<<Treap::getpre(x)<<endl;
		if(op==6) cout<<Treap::getnxt(x)<<endl;
	}
	return 0;
}
