#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,m,s;
vector <int> P[maxn];
int fa[maxn][40];
int deep[maxn];
void dfs(int x,int frt) {
	fa[x][0]=frt;
	deep[x]=deep[fa[x][0]]+1;
	for(int i=1;i<=31;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<P[x].size();i++) {
		if(P[x][i]==frt) continue;
		dfs(P[x][i],x);
	}
}
int LCA(int x,int y) {
	if(deep[x]>deep[y]) swap(x,y);
	int tmp=deep[y]-deep[x],ans=0;
	for(int i=0;tmp;i++,tmp>>=1) if(tmp&1) y=fa[y][i];
	if(y==x) return x;
	for(int i=30;i>=0;i--) {
		if(fa[x][i]!=fa[y][i]) {
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
signed main(){
	
	memset(fa,0,sizeof(fa));
	memset(deep,0,sizeof(deep));
	scanf("%lld %lld %lld",&n,&m,&s);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		P[x].push_back(y);
		P[y].push_back(x);
	}
	dfs(s,0);
	while(m--) {
		int a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",LCA(a,b));
	}
	return 0;
}

