#include <bits/stdc++.h>
#define int long long
using namespace std;
int aa,bb,pp;
long long binpow(long long a, long long b,long long p) {
	if (b == 0) return 1;
	long long res = binpow(a,b/2,p)%p;
	if (b % 2) return res%p*res%p*a%p;
	else return res%p*res%p;
}
signed main() {
	scanf("%lld%lld%lld",&aa,&bb,&pp);
	printf("%lld^%lld mod %lld=%lld",aa,bb,pp,binpow(aa,bb,pp));
	return 0;
}

