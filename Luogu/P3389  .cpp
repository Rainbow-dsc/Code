#include<bits/stdc++.h>
#define int  long long
#define maxn 105
using namespace std;
int n;
double a[maxn][maxn];
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) for(int j=1; j<=n+1; j++) scanf("%lf",&a[i][j]);
	for(int i=1; i<=n; i ++) {
		int f=i;
		while(a[f][i]==0&&f<=n) f++;
		if(f==n+1) {
			printf("No Solution");
			return 0;
		}
		for(int j=1; j<=n+1; j++) swap(a[i][j],a[f][j]);
		for(int j=n+1; j>=i; j--) a[i][j]/=a[i][i];
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			for(int k=n+1; k>=i; k--) a[j][k]-=a[i][k]*a[j][i];
		}
	}
	for(int i=1; i<=n; i++) printf("%.2lf\n",a[i][n+1]);
	return 0;
}
