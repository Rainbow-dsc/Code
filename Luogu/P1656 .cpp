#include<bits/stdc++.h>
#define int long long
#define maxn 10001
using namespace std;
int n,m,tim=0,cnt;
int dfn[maxn],low[maxn];
vector <int> P[maxn];
struct aa{
	int from,to;
}ans[maxn];
bool cmp(aa x,aa y) {
	if(x.from!=y.from) return x.from<y.from;
	else return x.to<y.to;
}
void Tarjan(int x,int fa) {
	dfn[x]=low[x]=++tim;
	bool flag=false;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(dfn[now] ) {
			if(now==fa&&!flag) flag=true;
			else low[x]=min(low[x],dfn[now]);
		} 
		if(!dfn[now]) {
			Tarjan(now,x);
			if(dfn[x]<low[now]) ans[++cnt].from=min(now,x),ans[cnt].to=max(now,x);
			low[x]=min(low[x],low[now]);
		}
	}
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		P[x].push_back(y);
		P[y].push_back(x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,i);
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) printf("%lld %lld\n",ans[i].from,ans[i].to); 
	return 0;
}
