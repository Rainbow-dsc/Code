#include<bits/stdc++.h>
#define int long long
#define maxn 1005
#define mod 998244353
using namespace std;
int T,id;
int sum[maxn][maxn];
char Map[maxn][maxn];
signed main() {
	scanf("%lld %lld",&T,&id);
	while(T--) {
		memset(sum,0,sizeof(sum));
		int n,m,c,f,ansc=0,ansf=0;
		scanf("%lld %lld %lld %lld",&n,&m,&c,&f);
		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>Map[i][j];
		for(int i=1; i<=n; i++) {
			for(int j=m-1; j>=1; j--) {
				if(Map[i][j]=='1') sum[i][j]=-1;
				else if(Map[i][j+1]=='0') sum[i][j]=sum[i][j+1]+1;
			}
		}
		//预处理:能种花的区域的个数. 
		for(int j=1; j<m; j++) {
			int jis=0,jil=0,jilf=0;
			for(int i=1; i<=n; i++) {
				if(sum[i][j]==-1) {
					jilf=jis=jil=0;
					continue;
				}
				ansc=ansc%mod+(sum[i][j]*(jil%mod))%mod;//乘法原理 
				ansf=(ansf%mod+jilf%mod)%mod;
				jilf=(jilf+(sum[i][j]*(jil%mod))%mod)%mod;
				jil+=max(0ll,sum[i-1][j]);
			}
		}
		printf("%lld %lld\n",(c*ansc)%mod,(f*ansf)%mod);
	}
	return 0;
}

