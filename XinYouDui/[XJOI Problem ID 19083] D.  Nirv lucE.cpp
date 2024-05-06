#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m,c,o;
int s[maxn];
signed main(){
	freopen("nirvluce*.in","r",stdin);
	freopen("nirvluce*.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&o);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(int l=0;l<c;l++) {
		int ans=(n-l-1)*(n-l)*(n-l+1)*(n-l+2)/12;
		printf("%lld ",ans);
	}
	return 0;
}

