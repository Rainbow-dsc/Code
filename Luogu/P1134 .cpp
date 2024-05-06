#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[]={6,6,2,6,4,4,4,8,4,6},b[]={6,8,4,2},r=1,n;
signed main() {
	scanf("%lld",&n);
	while(n)r=r*a[n%10]*b[(n=n/5)%4]%10;
	printf("%lld",r);
	return 0;
}
