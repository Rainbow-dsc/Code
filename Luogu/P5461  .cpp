#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[1100][1100];
signed main() {
	scanf("%lld",&n);
	n=(1<<n);
	a[0][n+1]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			a[i][j]=a[i-1][j]^a[i-1][j+1];
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

