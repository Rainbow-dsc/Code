#include<bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int n,m,q;
int a[maxn];
int b[maxn][maxn];
signed main(){
	scanf("%lld %lld %lld",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%lld",&b[i][j]);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) b[i][j]+=b[i-1][j]; 
	while(q--) {
		int x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		cout<<(a[y]+b[x][y]-a[z]-b[x][z])<<endl;
	}
	return 0;
}

