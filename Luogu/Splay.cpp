#include<bits/stdc++.h>
#define int long long
#define maxn 1100005
#define l(p) child[p][0]
#define r(p) child[p][1]
#define cp(z) child[p][z]
#define cu(z) child[u][z]
#define Sret(z) { Splay(u); return (z); }
using namespace std;
int root,t,las,ans;
int fa[maxn],siz[maxn],cnt[maxn],val[maxn];
int child[maxn][2];
struct Sp {
	void change_size(int p) {
		siz[p]=siz[l(p)]+siz[r(p)]+cnt[p];
	}
	bool child_side(int p) {
		return p==r(fa[p]);
	}
	void clear(int p) {
		l(p)=r(p)=fa[p]=val[p]=cnt[p]=siz[p]=0;
	}
	void rotate(int p) {
		int u=fa[p],x=fa[u],q=child_side(p);
		cu(q)=cp(q^1);
		if(cp(q^1)) fa[(cp(q^1))]=u;
		cp(q^1)=u;
		fa[u]=p,fa[p]=x;
		if(x) child[x][u==r(x)]=p;
		change_size(p);
		change_size(u);
	}
	void Splay(int p) {
		for(int q=fa[p]; q=fa[p],q; rotate(p)) if(fa[q]) rotate(child_side(p)==child_side(q)?q:p);
		root=p;
	}
	void Insert(int p) {
		if(!root) {
			val[++t] = p;
			++cnt[root=t];
			++siz[t];
			return;
		}
		int u=root,x=0;
		while(true) {
			if (val[u]==p) {
				++cnt[u];
				change_size(u);
				change_size(x);
				Splay(u);
				return;
			}
			x=u;
			u=cu(val[u]<p);
			if(!u) {
				val[++t]=p;
				++cnt[t];
				fa[t]=x;
				child[x][val[x]<p]=t;
				++siz[t];
				change_size(x);
				Splay(t);
				return;
			}
		}
	}
	int Rank(int p) {
		int u=root,x=0;
		while (true) {
			if(p<val[u]) u=l(u);
			else {
				x+=siz[l(u)];
				if(p==val[u]) Sret(x+1);
				x+=cnt[u];
				u=r(u);
			}
		}
	}
	int Pth(int p) {
		int u=root;
		while (true) {
			if (l(u)&&p<=siz[l(u)]) u=l(u);
			else {
				p-=cnt[u]+siz[l(u)];
				if(p<1) Sret(val[u]);
				u=r(u);
			}
		}
	}
	int PreSuc(bool p) {
		int u=p?r(root):l(root);
		while (p?l(u):r(u)) u=p?l(u):r(u);
		Sret(u);
	}
	void Delete(int p) {
		Rank(p);
		int u=root,x;
		if (cnt[u]>1) {
			--cnt[u];
			--siz[u];
			return;
		}
		if (!l(u)&&!r(u)) {
			clear(u);
			root=0;
			return;
		}
		if (!l(u)) {
		    root=r(u);
			fa[root]=0;
			clear(u);
			return;
		}
		if (!r(u)) {
		    root=l(u);
			fa[root] = 0;
			clear(u);
			return;
		}
		fa[r(u)]=x=PreSuc(false);
		r(x)=r(u);
		clear(u);
	}
} Tree;
inline int Read() {
	char c=getchar();
	int p=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>47&&c<58) p=(p<<3)+(p<<1)+c-48,c=getchar();
	return p;
}
signed main() {
	int n=Read(), m=Read();
	for(int i=1; i<=n; i++) {
		int a=Read();
		Tree.Insert(a);
	}
	while(m--) {
		int opt=Read(),x=Read()^las;
		if(opt==1) Tree.Insert(x);
		if(opt==2) Tree.Delete(x);
		if(opt==3) Tree.Insert(x),las=Tree.Rank(x),Tree.Delete(x);
		if(opt==4) las=Tree.Pth(x);
		if(opt>=5) Tree.Insert(x),las=val[Tree.PreSuc((opt-5))],Tree.Delete(x);
		if(opt>2&&las) ans^=las;
	}
	printf("%lld",ans);
	return 0;
}
