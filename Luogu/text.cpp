#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	while(1) {
		int n;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			int x=i;
			while(x) {
				if(x%2==0) printf("0");
				else printf("1");
				x>>=1;
			}
			puts("");
		}
	}
	return 0;
}

