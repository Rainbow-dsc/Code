#include<bits/stdc++.h>
#define int long long
#define maxn 300005
using namespace std;
int tid,n,m,b[maxn],c[maxn];
map<int,int> P,Q;
int maxb,maxc,sumb,sumc;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld",&tid);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]),P[b[i]]++,maxb=max(b[i],maxb),sumb+=b[i];
	for(int i=1;i<=m;i++) scanf("%lld",&c[i]),Q[c[i]]++,maxc=max(maxc,c[i]),sumc+=c[i];
	if(maxb!=maxc) {
		printf("-1");
		return 0;
	}
	int xx=0;
	for(int i=1;i<=n;i++) {
		if(P[b[i]]&&Q[b[i]]) P[b[i]]--,Q[b[i]]--,xx+=b[i];
	}
	cout<<sumb+sumc-xx;
	return 0;
}
