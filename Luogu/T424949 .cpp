#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,ans=-1e18;
int a[maxn];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) {
		ans=max(ans,a[i]-a[i+1]);
	}
	cout<<ans;
	return 0;
}

