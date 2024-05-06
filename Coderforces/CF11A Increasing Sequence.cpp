#include<bits/stdc++.h>
using namespace std;
signed main() {
	int n,s,ans=0,a[10001];
	cin>>n>>s;
	for(register int i=1; i<=n; i++) cin>>a[i];
	for(register int i=1; i<=n-1; i++) {
		if(a[i]>=a[i+1]) {
			ans+=(a[i]-a[i+1])/s+1;
			a[i+1]+=((a[i]-a[i+1])/s+1)*s;
		}
	}
	cout<<ans<<endl;
	return 0;
}
