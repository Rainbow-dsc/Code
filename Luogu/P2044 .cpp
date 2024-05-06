#include<bits/stdc++.h>
#define int long long
#define double long double
#define maxn 105
using namespace std;
int m,a,c,x0,n,g;
struct Mar{
	int c[maxn][maxn];
}A,T;
int mul(int a,int b) {
	return (a*b-(int)((double)a/m*b)*m+m)%m;
}
Mar operator * (Mar x,Mar y) {
	Mar p;
	for(int i=1;i<maxn;i++) for(int j=1;j<maxn;j++) p.c[i][j]=0;
	for(int i=1; i<=2; i++) for(int j=1; j<=2; j++) for(int k=1; k<=2; k++) p.c[i][j]+=mul(x.c[i][k],y.c[k][j]),p.c[i][j]%=m;
	return p;
}
signed main(){
	scanf("%lld %lld %lld %lld %lld %lld",&m,&a,&c,&x0,&n,&g);
	A.c[1][1]=a,A.c[1][2]=c;
	A.c[2][1]=0,A.c[2][2]=1;
	T.c[1][1]=x0,T.c[2][1]=1;
	while(n) {
		if(n&1) T=A*T;
		A=A*A;
		n>>=1;
	}
	cout<<T.c[1][1]%g;
	return 0;
}

