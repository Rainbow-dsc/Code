#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t,n,k,sum,cnt;
int a[maxn];
vector <int> P[maxn];
int dfs(int x,int fa) {
	int noww=a[x],ans;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		if(fa==now) continue;
		ans=dfs(now,x);
		if(ans==sum) cnt++;
		else noww^=ans;
	}
	return noww;
}
signed main(){
	scanf("%lld",&t);
	while(t--) {
		memset(P,0,sizeof(P));
		sum=0,cnt=0;
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum^=a[i];
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%lld %lld",&u,&v);
			P[u].push_back(v);
			P[v].push_back(u);
		}
		if(!sum) printf("YES\n");
		else if(k>=3){
			dfs(1,0);
			if(cnt>=2) printf("YES\n");
			else printf("NO\n");
		} else printf("NO\n");
	}
    return 0;
}

