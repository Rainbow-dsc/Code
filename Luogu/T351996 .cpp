#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
unordered_map <int,int> p;
signed main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%lld",&x);
		p[x*i]++;
	}
	int ans=0;
	for(int i=1;i<=m;i++) {
		int x;
		scanf("%lld",&x);
		if(x==0) continue;
		ans+=p[x*i];
	}
	printf("%lld",ans);
	return 0;
}
