#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
bool vis[maxn];
signed main() {
	freopen("kthmax.in","r",stdin);
	freopen("kthmax.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]),vis[a[i]]=true;
	for(int i=1; i<=m; i++) {
		int op;
		scanf("%lld",&op);
		if(op==1) {
			int l,r,x,y;
			scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
			for(int j=l; j<=r; j++) if(a[j]==x) a[j]=y,vis[x]=false,vis[y]=true;
		}
		if(op==2) {
			int cnt=0;
			int l,r,k;
			scanf("%lld %lld %lld",&l,&r,&k);
			for(int k=l; k<=r; k++) {
				for(int j=1; j<=100; j++) {
					if(cnt==k) printf("%lld\n",j);
					if(vis[i]==false) cnt++;
				}
			}
		}
	}
	return 0;
}

