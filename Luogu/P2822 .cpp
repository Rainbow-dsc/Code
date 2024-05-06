#include <bits/stdc++.h>
#define int long long
#define maxn 2004
using namespace std;
int t,k;
int C[maxn][maxn],ans[maxn][maxn];
void init(int n){
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
			if(C[i][j]==0)ans[i][j]++;
		}
		ans[i][i+1]=ans[i][i];
	}
}
signed main() {
	scanf("%lld %lld",&t,&k);
	init(2000);
	while(t--){
		int n,m;
		scanf("%lld %lld",&n,&m);
		if(m>n) printf("%lld\n",ans[n][n]);
		else printf("%lld\n",ans[n][m]);
	}
	return 0;
}
