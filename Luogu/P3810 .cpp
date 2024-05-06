#include<bits/stdc++.h>
#define maxn 100005
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int n,k,tot=0,m,sum[maxn<<5],f[maxn];
struct aa{ int x,y,z,cnt,ans; } a[maxn],w[maxn];
bool cmp1(aa x,aa y){
	if(x.x!=y.x) return x.x<y.x;
	if(x.y!=y.y) return x.y<y.y;
	return x.z<y.z;
}
bool cmp2(aa x,aa y) {
	if(x.y!=y.y) return x.y<y.y;
	return x.z<y.z;
}
void push_up(int rt) { sum[rt]=sum[lc]+sum[rc]; }
void update(int l,int r,int rt,int pos,int x) {
	if(l==r) return (void)(sum[rt]+=x);
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,lc,pos,x);
	else update(mid+1,r,rc,pos,x);
	push_up(rt);
}
int get_num(int l,int r,int rt,int s,int t,int ans=0){
	if(s>t) return 0;
	if(s<=l&&r<=t) return sum[rt];
	int mid=(l+r)>>1;
	if(s<=mid) ans+=get_num(l,mid,lc,s,t);
	if(t>mid) ans+=get_num(mid+1,r,rc,s,t);
	return ans;
}
void solve(int l,int r) {
	if(l==r) return ;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	sort(w+l,w+mid+1,cmp2),sort(w+mid+1,w+r+1,cmp2);
	int i=l,j=mid+1;
	while(j<=r) {
		while(i<=mid&&w[i].y<=w[j].y) update(1,k,1,w[i].z,w[i].cnt),i++;
		w[j++].ans+=get_num(1,k,1,1,w[j].z);
	}
	for(int t=l;t<i;t++) update(1,k,1,w[t].z,-w[t].cnt);
}
signed main(){
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+n+1,cmp1);
	for(int i=1; i<=n; i++) {
		tot++;
		if(i==n||a[i].x!=a[i+1].x||a[i].y!=a[i+1].y||a[i].z!=a[i+1].z)  w[++m]=a[i],w[m].cnt=tot,tot=0;
	}
	solve(1,m);
	for(int i=1; i<=m; i++) f[w[i].ans+w[i].cnt-1]+=w[i].cnt;
	for(int i=0; i<n; i++) printf("%lld\n",f[i]);
	return 0;
}
