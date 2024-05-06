#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int T,n;
int fa[maxn];
map<pair<int,int>,bool> P;
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int cnt() {
	int res=0;
	for(int i=1; i<=n; i++) if(fa[i]==i) res++;
	return res;
}
signed main() {
	scanf("%lld",&T);
	while(T--) {
		P.clear();
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) fa[i]=i;
		int mn=0,mx=n;
		for(int i=1; i<=n; i++) {
			int u;
			scanf("%lld",&u);
			if(P[make_pair(u,i)]) continue;
			P[make_pair(i,u)]=1;
			int t1=find(u),t2=find(i);
			if(t1==t2) mn++;
			else fa[t1]=t2;
		}
		mx=cnt();
		if(mx>mn) mn++;
		printf("%lld %lld\n",mn,mx);
	}
	return 0;
}
