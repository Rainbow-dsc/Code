#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n;
int siz[maxn];
vector <int> P[maxn];
void dfs(int x) {
	if(!P[x].size()) {
		siz[x]=1;
		return ;
	}
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		dfs(now);
		siz[x]+=siz[now];
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=2;i<=n;i++) {
		int fa;
		scanf("%lld",&fa);
		P[fa].push_back(i);
	}
	dfs(1);
	sort(siz+1,siz+n+1);
	for(int i=1;i<=n;i++) printf("%lld ",siz[i]);
    return 0;
}

