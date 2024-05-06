#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
struct aa{
	int u,w;
};
int n,cnt=0;
int a[maxn],vis[maxn];
vector <aa> P[maxn];
void dfs(int x,int sum) {
	if(vis[maxn]||sum>a[x]) return ;
	cnt++,vis[x]=1;
	for(int i=0;i<P[x].size();i++) {
		aa now=P[x][i];
		dfs(now.u,max(sum+now.w,now.w));
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++) {
		int p,c;
		scanf("%lld %lld",&p,&c);
		P[p].push_back({i,c});
	}
	dfs(1,0);
	printf("%lld",n-cnt);
    return 0;
}
