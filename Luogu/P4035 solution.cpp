#include<bits/stdc++.h>
#define int long long
#define N 120
#define eps 1e-8 
using namespace std;
int n;
double a[N][N],b[N],pos[N][N];
signed main() {
	scanf("%lld",&n);
	for (int i=1; i<=n+1; i++) for (int j=1; j<=n; j++) scanf("%lf",&pos[i][j]);
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) a[i][j]=2*(pos[i][j]-pos[i+1][j]),b[i]+=pos[i][j]*pos[i][j]-pos[i+1][j]*pos[i+1][j];
	for (int i=1; i<=n; i++) {
		int row=i;
		for (int j=i+1; j<=n; j++) if (fabs(a[j][i])>fabs(a[row][i])) row=j;
		if (fabs(a[row][i])<eps) break;
		if (row^i) swap(a[i],a[row]),swap(b[i],b[row]);
		for (int j=1; j<=n; j++) {
			if(i==j) continue;
			double rate=a[j][i]/a[i][i];
			for(int k=i; k<=n; k++) a[j][k]-=a[i][k]*rate;
			b[j]-=b[i]*rate;
		}
	}
	for (int i=1; i<n; i++) printf("%.3lf ",b[i]/a[i][i]);
	printf("%.3lf\n",b[n]/a[n][n]);
	return 0;
}
