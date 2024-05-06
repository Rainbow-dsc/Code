#include<bits/stdc++.h>
#define int long long
#define maxn 33000
using namespace std;
int n,w=0;
int a[maxn];
set<int> s;
signed main() {
	scanf("%lld", &n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	s.insert(a[1]);
	for(int i=2;i<=n;++i) {
		set<int>::iterator p=s.lower_bound(a[i]);
		if (p == s.end()) w+=a[i]-*--p;
		else if (p == s.begin()) w+=*p-a[i];
		else {
			int j=*p-a[i];
			--p;
			if (a[i]-*p<j) j=a[i]-*p;
			w+=j;
		}
		s.insert(a[i]);
	}
	printf("%lld\n", w+a[1]);
	return 0;
}
