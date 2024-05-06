#include<bits/stdc++.h>
#define int long long
#define maxn 30004
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int n,q,id;
int w[maxn],fa[maxn],siz[maxn],deep[maxn];
int rk[maxn],dfn[maxn],hson[maxn],top[maxn];
vector <int> P[maxn];
struct aa{
	int maxx,sum;
}a[maxn<<2];
void dfs1(int x) {
	siz[x]=1,hson[x]=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa[x]) continue;
		deep[now]=deep[x]+1;
		fa[now]=x;
		dfs1(now);
		siz[x]+=siz[now];
		if(siz[now]>siz[hson[x]]) hson[x]=now;
	}
}
void dfs2(int x,int tp) {
	top[x]=tp,dfn[x]=++id,rk[id]=x;
	if(hson[x]) dfs2(hson[x],tp);
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa[x]||now==hson[x]) continue;
		dfs2(now,now);
	}
}
void push_up(int rt) {
	a[rt].maxx=max(a[lc].maxx,a[rc].maxx);
	a[rt].sum=a[lc].sum+a[rc].sum;
}
void build(int rt,int l,int r) {
	if(l==r) {
		a[rt].sum=w[rk[l]];
		a[rt].maxx=w[rk[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int pos,int x) {
	if(l==r) {
		a[rt].maxx=a[rt].sum=x;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(lc,l,mid,pos,x);
	else update(rc,mid+1,r,pos,x);
	push_up(rt);
}
int query_max(int rt,int l,int r,int L,int R) {
	if(L>R) return 0;
	if(L<=l&&r<=R) return a[rt].maxx;
	int mid=(l+r)>>1;
	if(L>mid) return query_max(rc,mid+1,r,L,R);
	if(R<=mid) return query_max(lc,l,mid,L,R);
	return max(query_max(lc,l,mid,L,R),query_max(rc,mid+1,r,L,R));
}
int query_sum(int rt,int l,int r,int L,int R) {
	if(L>R) return 0;
	if(L<=l&&r<=R) return a[rt].sum;
	int mid=(l+r)>>1,sum=0;
	if(L<=mid) sum+=query_sum(lc,l,mid,L,R);
	if(R>mid) sum+=query_sum(rc,mid+1,r,L,R);
	return sum;
}
int Q_max(int x,int y) {
   int Maxn=-1e18;
   while(top[x]!=top[y]) {
      if(deep[top[x]]<deep[top[y]]) swap(x,y);
      Maxn=max(Maxn,query_max(1,1,n,dfn[top[x]],dfn[x]));
      x=fa[top[x]];
   }
   if(deep[x]>deep[y]) swap(x,y);
   Maxn=max(Maxn,query_max(1,1,n,dfn[x],dfn[y]));
   return Maxn;
}
int Q_sum(int x,int y) {
   int tot=0;
   while(top[x]!=top[y]) {
      if(deep[top[x]]<deep[top[y]]) swap(x,y);
      tot+=query_sum(1,1,n,dfn[top[x]],dfn[x]);
      x=fa[top[x]];
   }
   if(deep[x]>deep[y])swap(x,y);
   tot+=query_sum(1,1,n,dfn[x],dfn[y]);
   return tot;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		P[x].push_back(y);
		P[y].push_back(x);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	fa[1]=deep[1]=1;
	dfs1(1);dfs2(1,1);
	build(1,1,n);
	scanf("%lld",&q);
	while(q--) {
		string s;
		cin>>s;
		if(s[0]=='C') {
			int x,y;
			scanf("%lld %lld",&x,&y);
			update(1,1,n,dfn[x],y);
		}
		if(s[1]=='M') {
			int x,y;
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",Q_max(x,y));
		}
		if(s[1]=='S') {
			int x,y;
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",Q_sum(x,y));
		}
	}
    return 0;
}
