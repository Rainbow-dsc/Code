#include<bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int T;
int a[105];
signed main(){
	scanf("%lld",&T);
	while(T--) {
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++) {
			ans++;
			if(a[i]==ans) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
