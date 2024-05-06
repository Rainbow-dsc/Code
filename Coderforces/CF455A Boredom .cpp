#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num[100005],x,f[100005][2],maxn;
signed main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x);
		maxn=max(maxn,x);
		num[x]++;
	}
	for(long long i=1;i<=maxn;i++){
		f[i][0]=max(f[i-1][1],f[i-1][0]);
		f[i][1]=f[i-1][0]+num[i]*i;
	}
	printf("%lld",max(f[maxn][0],f[maxn][1]));
	return 0;
}
