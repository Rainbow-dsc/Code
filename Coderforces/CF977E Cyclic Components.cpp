#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,m;
vector<int> P[maxn];
bool vis[maxn];
int ans=0;
void dfs(int x){
	ans++;
	vis[x]=true;
	for(int i=0;i<P[x].size();i++) 
		if(vis[P[x][i]]==false) 
			dfs(P[x][i]);
}
signed main(){
	memset(vis,false,sizeof(vis));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) {
		int u,w;
		scanf("%lld%lld",&u,&w);
		P[u].push_back(w);
		P[w].push_back(u);
	}
	for(int i=1;i<=n;i++) 
		if(P[i].size()!=2) 
			dfs(i);
	int sum=0;
	for(int i=1;i<=n;i++) {
		if(vis[i]==false) {
			ans=0;
			dfs(i);
			if(ans>2) sum++;
		}
	}
	cout<<sum;
	return 0;
}

