#include<bits/stdc++.h>
#define int long long
#define maxn 6000010
#define X 100000005
using namespace std;
int n,q,k;
int pri[maxn];
bool vis[X];
void init() {
	int cnt=0;
	vis[1]=1;
	for (int i = 2 ; i < X; i++) {
		if (!vis[i]) pri[++cnt] = i;
		for (int j = 1; j <= cnt&&i*pri[j]<X; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
signed main() {
//	freopen("P3383_1.in","r",stdin);
//	freopen("P3383.out","w",stdout); 
	scanf("%lld %lld",&n,&q);
	init();
	while(q--) {
		int k;
		scanf("%lld",&k);
		printf("%lld\n",pri[k]);
	}
	return 0;
}
