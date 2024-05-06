#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int t,n,k,c,ans;
vector <int> P[maxn];
int dfs(int x,int fa,int deep) {
	int max1=0,max2=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(now==fa) continue;
		int de=dfs(now,x,deep+1)+1;
		if(de>max1) max2=max1,max1=de;
		else max2=max(max2,de); 
	}
	ans=max(ans,max1*k+max(0ll,max2*(k-c)-deep*c));
	return max1;
}
signed main(){
	scanf("%lld",&t);
	while(t--) {
		ans=0;
		memset(P,0,sizeof(P));
		scanf("%lld %lld %lld",&n,&k,&c);
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%lld %lld",&u,&v);
			P[u].push_back(v);
			P[v].push_back(u);
		}
		dfs(1,-1,0);
		printf("%lld\n",ans);
	}
    return 0;
}

