#include<bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int n,ans=1e9,t[maxn],id[maxn];
bool vis[maxn];
void f(int x) {
	if(vis[x]==true) return ;
	vis[x]=true;
	id[t[x]]--;
	if(id[t[x]]==0) f(t[x]);
}
int dfs(int st,int x,int step) {
	if(st==t[x]) return step+1;
	vis[x]=true;
	dfs(st,t[x],step+1);
}
signed main() {
	memset(vis,false,sizeof(vis));
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&t[i]);
		id[t[i]]++;
	}
	for(int i=1; i<=n; i++) if(id[i]==0) f(i);
	for(int i=1; i<=n; i++) if(vis[i]==false) ans=min(ans,dfs(i,t[i],1));
	printf("%lld",ans);
	return 0;
}
