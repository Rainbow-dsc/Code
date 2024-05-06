#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,d[maxn];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
	int ans=0;
	for(int i=1;i<=n;i++) if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
	cout<<ans;
	return 0;
}
