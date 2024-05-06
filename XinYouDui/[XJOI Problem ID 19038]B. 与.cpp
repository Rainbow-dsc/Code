#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,l[N],r[N];
ll x[N];
bool fail[N];
int pre[N],suf[N];
int c[N],fir[N],las[N],b[N];
namespace Solve {
	void main() {
		cin>>n>>m;
		for(int i=1; i<=m; i++)cin>>l[i]>>r[i]>>x[i];
		for(int z=60; ~z; z--) {
			memset(pre,0,sizeof pre);
			memset(suf,0,sizeof suf);
			memset(c,0,sizeof c);
			for(int i=1; i<=m; i++) if(x[i]>>z&1) c[l[i]]++,c[r[i]+1]--;
			for(int i=2; i<=n; i++) c[i]+=c[i-1];
			for(int i=1; i<=n; i++) b[i]=b[i-1]+(c[i]==0);
			fir[n+1]=n+1;
			for(int i=n; i; i--) fir[i]=(c[i]==1?i:fir[i+1]);
			for(int i=1; i<=n; i++) las[i]=(c[i]==1?i:las[i-1]);
			for(int i=1; i<=m; i++) {
				if(!(x[i]>>z&1)) {
					if(b[r[i]]-b[l[i]-1])continue;
					if(fir[l[i]]<=las[r[i]]) {
						suf[l[i]]++;
						pre[r[i]]++;
					} else pre[0]++;
				}
			}
			for(int i=1; i<=n+1; i++) pre[i]+=pre[i-1];
			for(int i=n; ~i; i--) suf[i]+=suf[i+1];
			for(int i=1; i<=m; i++) {
				if(fail[i])continue;
				if(x[i]>>z&1) if((fir[l[i]]>las[r[i]]&&pre[n])||pre[fir[l[i]]-1]+suf[las[r[i]]+1]) fail[i]=1;
					else if(pre[n]>(b[r[i]]-b[l[i]-1]==0)) fail[i]=1;
			}
		}
		for(int i=1; i<=m; i++)cout<<(fail[i]?0:1);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	Solve::main();
	return 0;
}
