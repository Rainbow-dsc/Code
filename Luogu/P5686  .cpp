#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 500005
using namespace std;
int n;
int a[maxn],b[maxn];
int suma[maxn],sumb[maxn];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]),sumb[i]=sumb[i-1]+b[i];
	int ans=0;
	for(int l=1;l<=n;l++) for(int r=l;r<=n;r++) ans+=(suma[r]-suma[l-1])%mod*(sumb[r]-sumb[l-1])%mod;
	printf("%lld",ans%mod);
	return 0;
}
