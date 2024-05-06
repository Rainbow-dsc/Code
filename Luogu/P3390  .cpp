#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 205
using namespace std;
int n,k;
struct Mar {
	int a[maxn][maxn];

} A,P;
Mar operator *(Mar x,Mar y) {
	Mar p;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) p.a[i][j]=0;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) p.a[i][j]+=x.a[i][k]*y.a[k][j]%mod,p.a[i][j]%=mod;
	return p;
}
signed main() {
	scanf("%lld %lld",&n,&k);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%lld",&A.a[i][j]);
	for(int i=1; i<=n; i++) P.a[i][i]=1;
	while(k) {
		if(k&1) P=P*A;
		A=A*A;
		k>>=1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) cout<<P.a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

