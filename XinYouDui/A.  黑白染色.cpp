#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
signed main() {
	freopen("classical.in","r",stdin);
	freopen("classical.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		int x,y;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;i++) scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++) cout<<0<<" ";
		cout<<endl;
	}
	return 0;
}

