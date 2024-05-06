#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,l,r,ott,ans;
int fa[maxn],nxt[maxn],p[maxn],cs[maxn],vis[maxn];
__int128 a[maxn],b[maxn],c[maxn];
struct aa {
	int id,dat;
} t[maxn];
vector<int> v[maxn];
bool cmp1(aa x,aa y) {
	return x.dat<y.dat;
}
bool cmp2(aa x,aa y) {
	return x.id<y.id;
}
__int128 check1(__int128 gb,__int128 gc,__int128 gx,__int128 x) {
	if(gc<0) {
		if(gb+gc*gx<=0) return (x-gx+1);
		else {
			__int128 hh,t1,t2;
			t1=gb+gc*gx;
			hh=gb/(-gc);
			if(gb%(-gc)==0) hh--;
			t2=gb+gc*hh;
			if(hh<=x) return (x-hh+(t1+t2)*(hh-gx+1)/2);
			else {
				t2=gb+gc*x;
				return ((x-gx+1)*(t1+t2)/2);
			}
		}
	} else if(gc==0) {
		if(gb<=0) return (x-gx+1);
		else return (x-gx+1)*gb;
	} else {
		if(gb+gc*gx>0) {
			__int128 t1,t2;
			t1=gb+gc*gx;
			t2=gb+gc*x;
			return ((t1+t2)*(x-gx+1)/2);
		} else {
			__int128 t1,t2;
			__int128 hh=(-gb)/gc;
			hh++;
			t1=gb+gc*hh;
			t2=gb+gc*x;
			if(hh<=x) return (hh-gx+(x-hh+1)*(t1+t2)/2);
			else return (x-gx+1);
		}
	}
}
void dfs(int now,int last) {
	fa[now]=last;
	for(int i=0; i<v[now].size(); i++) {
		int yyy=v[now][i];
		if(yyy==last) continue;
		dfs(yyy,now);
	}
	return;
}
bool check(int x) {
	for(int i=1; i<=n; i++) t[i].dat=0;
	for(int i=1; i<=n; i++) {
		int gl=1,gr=n;
		while(gl<=gr) {
			int midd=(gl+gr)>>1;
			if(check1(b[i],c[i],midd,x)>=a[i]) {
				t[i].dat=midd;
				gl=midd+1;
			} else gr=midd-1;
		}
		if(check1(b[i],c[i],t[i].dat,x)<a[i]) return false;
	}
	for(int i=1; i<=n; i++) {
		vis[i]=0;
		nxt[i]=0;
		t[i].id=i;
	}
	sort(t+1,t+n+1,cmp1);
	int dy=1;
	vis[1]=1;
	for(int i=1; i<=n; i++) {
		int now=t[i].id;
		while(vis[now]==0&&now!=0) {
			vis[now]=-1;
			nxt[fa[now]]=now;
			now=fa[now];
		}
		now=nxt[now];
		while(vis[now]==-1&&now!=0) {
			vis[now]=dy+1;
			dy++;
			now=nxt[now];
		}
	}
	sort(t+1,t+n+1,cmp2);
	for(int i=1; i<=n; i++) if(vis[i]>t[i].dat) return false;
	return true;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[i]=x,b[i]=y,c[i]=z;
	}
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	l=1,r=1000000000;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
