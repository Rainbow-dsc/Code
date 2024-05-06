#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,k;
int deep[maxn],fa[maxn],siz[maxn],val[maxn];
vector <int> P[maxn];
void dfs(int x){
	siz[x]=1;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(fa[x]==now) continue;
		fa[now]=x;
		deep[now]=deep[x]+1;
		dfs(now);
		siz[x]+=siz[now];
	}
	val[x]=deep[x]-siz[x];
}
signed main(){
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%lld %lld",&u,&v);
		P[u].push_back(v);
		P[v].push_back(u);
	}
	deep[1]=1,fa[1]=1;
	dfs(1);
	sort(val+1,val+n+1);
	int ans=0;
	for(int i=n-k+1;i<=n;i++) ans+=val[i];
	printf("%lld",ans); 
    return 0;
}

