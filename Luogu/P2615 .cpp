#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[39][39];
signed main() {
	scanf("%lld",&n);
	memset(a,0,sizeof(a));
	a[1][(n+1)/2]=1;
	int li=1,lj=(n+1)/2;
	for(int k=2; k<=n*n; k++) {
		if(li==1&&lj!=n) a[n][lj+1]=k,li=n,lj++;
		else if(lj==n&&li!=1) a[li-1][1]=k,li--,lj=1;
		else if(li==1&&lj==n) a[2][lj]=k,li++;
		else if(li!=1&&lj!=n) {
			if(a[li-1][lj+1]==0) a[li-1][lj+1]=k,li--,lj++;
			else a[li+1][lj]=k,li++;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
		puts("");
	}
	return 0;
}
