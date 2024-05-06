#include <bits/stdc++.h>
#define int long long
#define maxn (int)(1e5+7)
using namespace std;
int T;
signed main() {
	scanf("%lld",&T);
	while(T--) {
		int a,b,m;
		scanf("%lld %lld %lld",&a,&b,&m);
		cout<<m/a+m/b+2<<endl;
	}
	return 0;
}

