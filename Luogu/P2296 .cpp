#include<bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n,m,s,t;
int deg[maxn];
int dis[maxn];
vector <int> P[maxn];
vector <int> F[maxn];
bool vis[maxn];
queue<int> Q;
void back(int x) {
	memset(vis,false,sizeof(vis));
	while(!Q.empty()) Q.pop();
	Q.push(x);
	vis[x]=true;
	while(!Q.empty()) {
		int pc=Q.front();
		Q.pop();
		for(int i=0;i<F[pc].size();i++) {
			int cr=F[pc][i];
			deg[cr]--;
			if(vis[cr]) continue;
			else {
				vis[cr]=true;
				Q.push(cr);
			}
		}
	}
}
void bfs(int x) {
	memset(vis,false,sizeof(vis));
	while(!Q.empty()) Q.pop();
	Q.push(x);
	vis[x]=true;
	while(!Q.empty()) {
		int pc=Q.front();
//		cout<<pc<<endl<<dis[pc]<<endl;
		Q.pop();
		for(int i=0;i<P[pc].size();i++) {
			int cr=P[pc][i];
			if(deg[cr]!=0||vis[cr]==true) continue;
			else {
				vis[cr]=true;
				Q.push(cr);
				dis[cr]=dis[pc]+1;
			}
		}
	}
}
signed main(){
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		deg[x]++;
		P[x].push_back(y);
		F[y].push_back(x);
	}
	scanf("%lld%lld",&s,&t);
	back(t);
	dis[s]=0,deg[t]=0;
//	for(int i=1;i<=n;i++) cout<<deg[i]<<" ";
	bfs(s);
	if(dis[t]==dis[0]) printf("-1");
	else printf("%lld",dis[t]);
	return 0;
}

