#include<bits/stdc++.h>
#define int long long
#define maxn 300005
using namespace std;
int n,m;
vector <int> P[maxn];
int dfn[maxn],low[maxn];
bool vis[maxn],flag[maxn];
int cnt=0,tim=0;
void Tarjan(int x,int fa) {
	vis[x]=true;
	dfn[x]=low[x]=++tim;
	int chi=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(!vis[now]) {
			chi++;
			Tarjan(now,x);
			low[x]=min(low[x],low[now]);
			if(fa!=x&&!flag[x]&&low[now]>=dfn[x]) {
				cnt++;
				flag[x]=true;
			}
		} else if(now!=fa) low[x]=min(low[x],dfn[now]);
	}
	if(fa==x&&chi>=2) {
		cnt++;
		flag[x]=true;
	} 
}
signed main(){
	memset(vis,false,sizeof(vis));
	memset(flag,false,sizeof(flag));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		P[x].push_back(y);
		P[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			tim=0;
			Tarjan(i,i);
		}
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++) if(flag[i]==true) printf("%lld ",i);
	return 0;
}
