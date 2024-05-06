#include<bits/stdc++.h>
#define int long long
#define maxn 5001
using namespace std;
int b,a[maxn];
signed main() {
	scanf("%lld",&b);
	while (b--) {
		int n,t,m,w=0;
		scanf("%lld%lld%lld", &n, &t, &m);
		for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
		while (m--) {
			int i,j;
			scanf("%lld",&i);
			a[i]-=2;
		}
		priority_queue<int> q;
		for (int i(1); i<=n; i++) if (a[i]<1) q.emplace(a[i]); else ++w;
		while (!q.empty()) {
			const int p(q.top());
			q.pop();
			t-=1-p;
			if (t<0) break;
			else ++w;
		}
		printf("%lld\n",w);
	}
	return 0;
}
