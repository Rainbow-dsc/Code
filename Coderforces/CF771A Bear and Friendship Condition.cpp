#include<bits/stdc++.h>
#define maxn 150005
#define int long long
using namespace std;
int n,m;
int fa[maxn];
int sum[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%lld%lld",&u,&v);
		int fu=find(u);
		int fv=find(v);
		if(fu!=fv) fa[fu]=fv,sum[fv]+=sum[fu];
	}
	int ans=0;
	for(int i=1;i<=n;i++) 
		if(find(i)==i) 
			ans+=sum[i]*(sum[i]-1)/2;
	if(ans==m) cout<<"YES";
	else cout<<"NO";
	return 0;
}

