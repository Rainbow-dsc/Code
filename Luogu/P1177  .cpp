#include <bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,a[maxn]; 
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}

