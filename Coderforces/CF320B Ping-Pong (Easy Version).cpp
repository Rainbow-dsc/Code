#include <bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n;
int cnt=0;
struct aa{
	int l,r;
}a[maxn];
bool vis[maxn];
void dfs(int now){
	vis[now]=true;
	for(int i=1;i<=cnt;i++) {
		aa pc=a[i];
		if(vis[i]) continue;
		if((pc.l<a[now].l&&a[now].l<pc.r)||(pc.l<a[now	].r&&a[now].r<pc.r)) dfs(i);
	}
}
signed main() {
	scanf("%lld",&n);
	while(n--) {
		int opt,x,y;
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1) {
			a[++cnt].l=x;
			a[cnt].r=y;
		} else {
			memset(vis,false,sizeof(vis));	
			dfs(x);
			if(vis[y]) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
