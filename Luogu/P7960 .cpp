#include <bits/stdc++.h>
#define int long long
#define maxn 10000100
using namespace std;
int T;
int vis[maxn],ans[maxn];
bool check(int x) {
	while(x) {
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void init() {
	int x;
	for (int i=1; i<=maxn-10; i++) {
		if(vis[i]) continue;
		if(check(i)) {
			for (int j=i; j<=maxn-10; j+=i) vis[j]=1;
			continue;
		}
		ans[x]=i;
		x=i;
	}
}
signed main() {
	init();
	scanf("%lld",&T);
	while (T--) {
		int x;
		scanf("%lld",&x);
		if(vis[x])  printf("-1\n");
		else printf("%lld\n",ans[x]);
	}
	return 0;
}
