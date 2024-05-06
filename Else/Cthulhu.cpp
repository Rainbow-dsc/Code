#include<bits/stdc++.h>
#define int long long 
#define maxn 1005
using namespace std;
int n,m;
int mp[maxn][maxn];
bool vis[maxn];
void dfs(int x){
	vis[x]=true;
	for(int i=1;i<=n;i++) {
		if(mp[x][i]==1&&vis[i]==false) {
			dfs(i);
		}
	}
}
signed main(){
	memset(vis,false,sizeof(vis));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%lld%lld",&u,&v);
		mp[u][v]=1;
		mp[v][u]=1;
	}
	if(m!=n) {
		cout<<"NO";
		return 0;
	}
	dfs(1);
	for(int i=1;i<=n;i++) {
		if(vis[i]==false) {
			cout<<"NO";
			return 0;
		}
	}
	cout<<"FHTAGN!";
	return 0;
} 
