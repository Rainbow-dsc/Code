#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define mod 10007
using namespace std;
int n;
int a[maxn];
int sum=0,ans=0;
vector <int> P[maxn];
void rainbow(int x) {
	int all=0,ma=0,mi=0,pc=0;
	for(int i=0;i<P[x].size();i++) {
		int now=P[x][i];
		all+=a[now];
		pc+=a[now]*a[now];
		if(a[now]>ma) mi=ma,ma=a[now];
		else if(a[now]>mi) mi=a[now];
	}
	ans=max(ans,mi*ma);
	sum=(sum%mod+(all*all-pc+mod)%mod)%mod;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		P[x].push_back(y);
		P[y].push_back(x);
	}
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=n; i++) rainbow(i); 
	printf("%lld %lld",ans,sum);
	return 0;
}

