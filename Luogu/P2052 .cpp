#include<bits/stdc++.h>
#define int long long
#define maxn 1000007
using namespace std;
int n,cnt,ans;
int siz[maxn];
struct aa{
	int u,w;
};
vector<aa> P[maxn];
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=0;i<P[x].size();i++) {
		int to=P[x][i].u;
		if(fa==to) continue;
		dfs(to,x);
		siz[x]+=siz[to];
		ans+=P[x][i].w*abs(2*siz[to]-n);
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		P[x].push_back((aa){y,z});
		P[y].push_back((aa){x,z});
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}

