#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,p,ans=-1e9,anss=1e9,pp,c;
int sum=0;
signed main() {
	scanf("%lld %lld",&n,&c);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a);
		if(i==1) p=a,pp=a;
		else p=max(a,a+p),pp=min(pp+a,a);
		ans=max(ans,p),anss=min(anss,pp);
		sum+=a;
	}
	if(c>0) {
		if(ans>0) printf("%lld",sum-ans+ans*c);
		else printf("%lld",sum);
	} else {
		if(anss>0) printf("%lld",sum);
		else printf("%lld",sum-anss+anss*c);
	}
	return 0;
}
