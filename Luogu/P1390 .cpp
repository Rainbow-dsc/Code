#include<bits/stdc++.h>
#define int long long
#define maxn 2000010
using namespace std;
int n,cnt=0,l,r,res,maxx,ans;
int prm[maxn],prs[maxn],miu[maxn],mis[maxn],vis[maxn];
void init() {
	mis[1]=miu[1]=1;
	for(int i=2; i<=n; i++) {
		if(!prm[i]) prs[++cnt]=i,miu[i]=-1;
		for(int j=1; j<=cnt; j++) {
			if(i*prs[j]>n) break;
			prm[i*prs[j]]=1;
			if(i%prs[j]==0) {
				miu[i*prs[j]]=0;
				break;
			} else miu[i*prs[j]]=-1*miu[i];
		}
		mis[i]=mis[i-1]+miu[i];
	}
}
signed main() {
	scanf("%lld",&n);init();
	for(int i=1; i<=n; i++) {
		res=0,l=1,maxx=n/i;
		while(l<=maxx) {
			r=maxx/(maxx/l);
			res+=(mis[r]-mis[l-1])*(maxx/l)*(maxx/l);
			l=r+1;
		}
		ans+=res*i;
	}
	cout<<((ans-((n+1)*n>>1))>>1);
	return 0;
}
