#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
#define maxn 70
using namespace std;
int n,cnt;
char mp[maxn][maxn];
int a[maxn][maxn][maxn][maxn];
inline int dfs(int a1,int b1,int a2,int b2) {
	if(a[a1][b1][a2][b2]!=-1) return a[a1][b1][a2][b2];
	if(a1==a2&&b1==b2) return a[a1][b1][a2][b2]=(mp[a1][b1]=='T');
	a[a1][b1][a2][b2]=max(a2-a1+1,b2-b1+1);
	for(int i=a1; i<a2; i++) a[a1][b1][a2][b2]=min(a[a1][b1][a2][b2],dfs(a1,b1,i,b2)+dfs(i+1,b1,a2,b2));
	for(int i=b1; i<b2; i++) a[a1][b1][a2][b2]=min(a[a1][b1][a2][b2],dfs(a1,b1,a2,i)+dfs(a1,i+1,a2,b2));
	return a[a1][b1][a2][b2];
}
signed main() {
	freopen("detection.in","r",stdin);
	freopen("detection.out","w",stdout);
	scanf("%lld",&n);
	memset(a,-1,sizeof(a));
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>mp[i][j];
	printf("%lld",dfs(1,1,n,n));
	return 0;
}
