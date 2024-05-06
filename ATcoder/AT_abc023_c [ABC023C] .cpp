#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
vector <int> P[maxn];
set <int>  h[maxn];
int r,c,k,n;
int sumr[maxn],sumc[maxn];
signed main() {
	scanf("%lld%lld%lld%lld",&r,&c,&k,&n);
	for(int i=1;i<=n;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		P[x].push_back(y);
		sumr[x]++;
		sumc[y]++;
	}
	for(int i=1;i<=c;i++) h[sumc[i]].insert(i);
	long long ans=0;
	for(int i=1;i<=r;i++) {
		if(k-sumr[i]<0) continue;
		ans+=h[k-sumr[i]].size();
		for(int j=0;j<P[i].size();j++) {
			if(h[k-sumr[i]].count(P[i][j]))   ans--;
			if(h[k-sumr[i]+1].count(P[i][j])) ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

