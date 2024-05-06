#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
int a[10],p[10];
signed main() {
	scanf("%lld",&T);
	while(T-- ) {
		int sum=0,cnt=0,ans=0;
		for(int i=1; i<=5; i++) scanf("%lld",&a[i]),sum+=a[i]*i,cnt+=a[i];
		for(int i=1; i<=5; i++) scanf("%lld",&p[i]);
		double max4=p[4]*1.0,max5=p[5]*1.0/2;
		int t=3*cnt-sum;
		if(t<=0) ans=0;
		else if(max5<max4) {
			if(t%2==0) ans=t/2*p[5];
			else ans=min((t/2+1)*p[5],t/2*p[5]+p[4]);
		} else ans=t*p[4];
		printf("%lld\n",ans);
	}
	return 0;
}
