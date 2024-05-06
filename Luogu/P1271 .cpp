#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[2000005];
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++) cout<<a[i]<<" "; 
	return 0;
}

