#include <bits/stdc++.h>
#define int long long
#define maxn 10001
using namespace std;
int n,m;
int a[maxn];
struct aa{
	int u,v,w;
};
vector <aa> P[maxn];
signed main() {
	scanf("%lld%lld",&n,&m);
	memset(P,0xcf,sizeof(P));
	cout<<0xcf;
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) {
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		P[u].push_back({v,w});
	}
	
	return 0;
}

