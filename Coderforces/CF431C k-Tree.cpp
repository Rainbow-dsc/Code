#include<bits/stdc++.h>
#define int long long
#define maxn 105
#define mod 1000000007
using namespace std;
int n,k,d;
int f[maxn][2];
signed main(){
	scanf("%lld %lld %lld",&n,&k,&d);
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=min(i,k);j++) {
			if(j<d) f[i][0]+=f[i-j][0],f[i][1]+=f[i-j][1];
			else f[i][1]+=f[i-j][1]+f[i-j][0];
			f[i][0]%=mod,f[i][1]%=mod;
		}
	}
	printf("%lld\n",f[n][1]);
    return 0;
}
