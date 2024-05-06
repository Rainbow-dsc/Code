#include<bits/stdc++.h>
#define RI int
#define err puts("asd")
#define ll long long
#define ull unsigned long long
#define LL __int128
#define db long double
#define mk make_pair
#define FL fflush(stdout)
#define eb emplace_back
#define FR(u,v) for(int i=h[u],v=a[i].t;i;i=a[i].n,v=a[i].t)
#define FB(x,z,y) for(int y=__lg(x&-x)+1,z=x;z;z^=z&-z,y=__lg(z&-z)+1)
#define FS(x,y) for(int y=x;y;y=(y-1)&x)
#define mem(a,b) memset(a,b,sizeof a)
#define yes puts("Yes")
#define no puts("No")
#define gg puts("-1")
#define vc vector
#define ex exit(0)
#define fi first
#define se second
//#define int long long
using namespace std;
const db eps=1e-15;
const db inf=1e12+5;
const db INF=1e18;
const int mod=1e9+7;
inline ll power(ll x,int y) {
	ll t=1;
	while(y) {
		if(y&1) t=t*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return t;
}
inline void gt(int &x,int &y) {
	if(x>y) swap(x,y);
}
inline void cmax(int &x,int y) {
	x<y?x=y:0;
}
inline void cmin(db &x,db y) {
	x>y?x=y:0;
}
inline void AD(int &x,int y) {
	x+=y;
	if(x>mod) x-=mod;
}
inline ll read() {
	ll s=0;
	char c=getchar();
	bool f=0;
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-48,c=getchar();
	return f?-s:s;
}
const int N=4e5+5;
struct wu {
	int n,t;
} a[N<<1];
int n,m,K,rt[N],tot,L[N],R[N],C[N],X[N];
int siz[N],pri[N],lc[N],rc[N],cnt,k;
db f[N],val[N],tag[N],sum[N];
int tong[N],stk[N],topf,h[N],p,fa[N],si[N],son[N],D;
pair<int,pair<int,int> >g[N];
vc<int>q[N],V[N];
inline void add(int u,int v) {
	a[++p].t=v;
	a[p].n=h[u];
	h[u]=p;
}
inline int New(db x,int y=0) {
	if(!y) y=++tot;
	else lc[y]=rc[y]=0;
	val[y]=x;
	f[y]=x;
	tag[y]=inf;
	siz[y]=1;
	pri[y]=rand();
	return y;
}
inline void up(int x) {
	if(!x) return;
	siz[x]=siz[lc[x]]+siz[rc[x]]+1;
	f[x]=f[lc[x]]+f[rc[x]]+val[x];
}
inline void calc(int x,db v) {
	f[x]=siz[x]*v;
	cmin(val[x],v);
	cmin(tag[x],v);
}
inline void down(int x) {
	if(tag[x]!=inf) {
		if(lc[x]) calc(lc[x],tag[x]);
		if(rc[x]) calc(rc[x],tag[x]);
		tag[x]=inf;
	}
}
inline void split(int rt,db k,int &x,int &y) {
	if(!rt) {
		x=y=0;
		return;
	}
	down(rt);
	if(val[rt]<=k) x=rt,split(rc[rt],k,rc[x],y);
	else y=rt,split(lc[rt],k,x,lc[y]);
	up(rt);
}
inline int merge(int x,int y) {
	if(!x||!y) return x^y;
	if(pri[x]>pri[y]) {
		down(x);
		rc[x]=merge(rc[x],y);
		return up(x),x;
	} else {
		down(y);
		lc[y]=merge(x,lc[y]);
		return up(y),y;
	}
}
ll res;
int now;
db vv,S,F;
inline void Do(int x,int &H) {
	if(!x) return;
	down(x);
	Do(lc[x],H);
	Do(rc[x],H);
	RI u,v;
	split(H,val[x],u,v);
	H=merge(merge(u,New(val[x],x)),v);
}
inline void ask(int x) {
	if(!x) return;
	down(x);
	if(now!=siz[lc[x]]+1&&vv-f[lc[x]]-val[x]>=val[x]*(now-siz[lc[x]]-1)) {
		vv-=f[lc[x]]+val[x];
		now-=siz[lc[x]]+1;
		S=val[x];
		ask(rc[x]);
	} else ask(lc[x]);
}
inline void solve(int u) {
	si[u]=V[u].size();
	FR(u,v) {
		solve(v);
		si[u]+=si[v];
		if(si[v]>si[son[u]]) son[u]=v;
	}
	if(son[u]) rt[u]=rt[son[u]];
	FR(u,v) if(v!=son[u]) Do(rt[v],rt[u]);
	RI x,y;
	for(RI v:V[u]) {
		split(rt[u],v,x,y);
		rt[u]=merge(merge(x,New(v)),y);
	}
	if(!X[u]) return;
	S=0;
	now=siz[rt[u]];
	vv=f[rt[u]]-X[u];
	if(vv<0) {
		if(rt[u]) calc(rt[u],0);
		res+=vv;
		return;
	}
	ask(rt[u]);
	split(rt[u],S,x,y);
	calc(y,vv/now);
	rt[u]=merge(x,y);
}
inline void getans(int x) {
	if(!x) return;
	down(x);
	getans(lc[x]);
	sum[++cnt]=val[x];
	getans(rc[x]);
}
ll P,Q,W;
db ans;
inline db get(int x) {
	if(x<W) return INF;
	return sum[x]+P-(x-W)*Q;
}
inline void work(int l,int r) {
	if(l>r) return;
	l=n-l;
	r=n-r;
	gt(l,r);
	W=l;
	RI mid,pos;
	while(l<=r) {
		mid=l+r>>1;
		if(get(mid)<=get(mid-1)) l=mid+1,pos=mid;
		else r=mid-1;
	}
	ans=min(ans,get(pos));
}
signed main() {
	ll x=0,y=0,z=0,u=0,v=0,SS=0;
	//freopen("12.in","r",stdin);
	//freopen("12.out","w",stdout);
	n=read();
	m=read();
	K=read();
	srand(time(0));
	for(RI i=1; i<=n; ++i) C[i]=read(),SS+=C[i];
	for(RI i=1; i<=m; ++i) L[i]=read(),R[i]=read(),X[i]=read(),res+=X[i],q[L[i]].eb(i);
	R[++m]=n;
	q[1].eb(m);
	for(RI i=1; i<=n; ++i) {
		topf-=tong[i];
		sort(q[i].begin(),q[i].end(),[](int x,int y) {return R[x]>R[y];});
		for(RI x:q[i]) {
			++tong[R[x]+1];
			if(stk[topf]) add(stk[topf],x);
			else D=x;
			stk[++topf]=x;
		}
		V[stk[topf]].eb(C[i]);
	}
	solve(D);
	getans(rt[D]);
	for(RI i=1; i<=cnt; ++i) sum[i]+=sum[i-1];
	while(K--) {
		k=read();
		z=0;
		P=Q=0;
		ans=INF;
		for(RI i=1; i<=k; ++i) {
			x=read();
			y=read();
			if(y/x<=n) g[++z]=mk(y/x,mk(y-y/x*x,x)),P+=y;
			else P+=x*n,Q+=x;
		}
		sort(g+1,g+z+1);
		g[z+1].fi=n;
		y=z+1;
		for(RI i=z; i>0; --i) {
			if(g[i].fi==g[i-1].fi) {
				g[i-1].se.fi+=g[i].se.fi;
				g[i-1].se.se+=g[i].se.se;
				continue;
			}
			work(g[i].fi+1,g[y].fi);
			P-=g[i].se.fi+Q*(g[y].fi-g[i].fi);
			Q+=g[i].se.se;
			y=i;
		}
		work(0,g[1].fi);
		printf("%.0Lf\n",ans+res);
	}
	return 0;
}
