#include<bits/stdc++.h>
#define int long long
#define maxn 1000006
using namespace std;
int n,cnt,dw[maxn];
struct aa{ int v,w; };
vector <aa> P[maxn];
struct acin{ int u,v,w; }a[maxn];
void dfs(int x,int fa) {
	for(int i=0;i<P[x].size();i++) {
		if(cnt&&P[x][i].v!=fa) dw[P[x][i].v]=1,cnt--;
		P[x][i].w=dw[x]^dw[P[x][i].v];
		if(P[x][i].v==fa) continue;
		dfs(P[x][i].v,x);
	}
}
signed main(){
	freopen("easy.in","r",stdin),freopen("easy.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		scanf("%lld %lld",&a[i].u,&a[i].v);
		P[a[i].u].push_back({a[i].v,0}),P[a[i].v].push_back({a[i].u,0});
	}
	printf("%lld\n",(n/2)*((n+1)/2));
	cnt=n/2,dfs(1,-1);
	for(int i=1;i<n;i++) for(int j=0;j<P[a[i].u].size();j++) if(P[a[i].u][j].v==a[i].v) printf("%lld ",P[a[i].u][j].w);
    return 0;
}
