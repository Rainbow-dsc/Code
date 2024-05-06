#include<bits/stdc++.h>
#define maxn 3005
#define mod 1000000007
#define int long long
int tid,t,n;
int gl[maxn],gr[maxn];
int tot[2][maxn][maxn];
void inc(int &x,int y) {
	x=((x+=y)>=mod?x-mod:x);
	return;
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&tid,&t);
	for(int wc=1; wc<=t; wc++) {
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) scanf("%lld%lld",gl+i,gr+i);
		memset(tot[(n+1)&1],0,sizeof tot[(n+1)&1]);
		tot[(n+1)&1][0][0]=1;
		for(int i=n; i; i--) {
			int now=i&1,oth=1-(i&1);
			for(int j=0; j<=n-i+1; j++) for(int k=0; k<=n-i-j+1; k++) tot[now][j][k]=0;
			for(int j=0; j<=n-i; j++)
				for(int k=0; k<=n-i-j; k++) {
					int nv=tot[oth][j][k];
					if(!nv)continue;
					if(gl[i]<=0&&gr[i]>=0) {
						inc(tot[now][j+1][k],nv);
						if(k)inc(tot[now][j][k-1],1ll*k*nv%mod);
					}
					if(gl[i]<=1&&gr[i]>=1) {
						inc(tot[now][j][k],2ll*nv*j%mod);
						if(j&&k)inc(tot[now][j-1][k-1],(2ll*nv*j%mod*k%mod+mod-2ll*nv*k%mod)%mod);
					}
					if(gl[i]<=2&&gr[i]>=2) {
						inc(tot[now][j][k+1],2ll*nv*j%mod);
						if(j) {
							inc(tot[now][j-1][k],(2ll*nv*j%mod*k%mod+mod-2ll*nv*k%mod)%mod);
							inc(tot[now][j-1][k],1ll*j*(j-1)%mod*nv%mod);
						}
						if(j>=2&&k) inc(tot[now][j-2][k-1],(1ll*j*(j-1)%mod*k%mod*nv%mod+mod-(2ll*k*(j-1)%mod*nv%mod))%mod);
					}
				}
		}
		printf("%lld\n",tot[1][1][0]);
	}
	return 0;
}
