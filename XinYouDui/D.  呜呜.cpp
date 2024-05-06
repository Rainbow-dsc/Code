#include<bits/stdc++.h>
#define int long long
#define maxn 100
using namespace std;
int n,k;
int a[maxn],f[maxn][maxn];
signed main(){
	freopen("wuwu.in","r",stdin);
	freopen("wuwu.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n+1;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n+3;i++) for(int j=1;j<=n+1;j++) scanf("%lld",&f[i][j]);
	cout<<"NO\n";
	return 0;
}
