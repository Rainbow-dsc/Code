#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans=0;
int main() {
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	printf("%lld",a[n]+a[n-1]);
    return 0;
}
