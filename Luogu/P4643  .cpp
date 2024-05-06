#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m;
int w[maxn];
bool cmp(int x,int y) {
	return x>y;
}
signed main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]),w[i]*=2;
	for(int i=1;i<=m;i++) {
		int u,v,x;
		scanf("%lld %lld %lld",&u,&v,&x);
		w[u]+=x;
		w[v]+=x;
	}
	sort(w+1,w+n+1,cmp);
	int ans=0;
	for(int i=1;i<n;i+=2) ans+=w[i]-w[i+1];
	cout<<ans/2;
	return 0;
}
