#include<bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n,m,ans[maxn];
struct aa{
	int v,w;
	bool operator < (const aa q) const{
		return w>q.w;	
	}
};
vector <aa> P[maxn];
priority_queue <aa> C;
bool vis[maxn];
signed main(){
	int s;
	scanf("%lld %lld %lld",&n,&m,&s);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		P[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++) ans[i]=1e18;
	ans[s]=0;
	C.push({s,0});
	while(!C.empty()) {
		aa tp=C.top();
		C.pop();
		if(vis[tp.v]) continue;
		vis[tp.v]=true;
		for(int i=0;i<P[tp.v].size();i++) {
			aa now=P[tp.v][i];
			if(ans[now.v]>ans[tp.v]+now.w) {
				ans[now.v]=ans[tp.v]+now.w;
				C.push({now.v,ans[now.v]});
			}
		} 
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}

