#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n,m,cnt=0;
int a[maxn],sum=0;
struct aa {
	bool vis=false;
	int ans;
} dpq[maxn],dph[maxn];
bool flag=true,flagg=true;
int op[maxn],xx[maxn];
signed main() {
//	freopen("subarray.in","r",stdin);
//	freopen("subarray.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]),sum+=a[i];
		if(a[i]<0) flag=false;
	}
	for(int i=1; i<=m; i++) {
		scanf("%lld %lld",&op[i],&xx[i]);
		cnt+=op[i];
		if(xx[i]<0) flagg=false;
	}
	dpq[1].ans=a[1];
	for(int i=2; i<=n; i++) {
		if(dpq[i-1].ans<0) dpq[i].vis=true,dpq[i].ans=a[i];
		else dpq[i].ans=dpq[i-1].ans+a[i],dpq[i].vis=false;
	}
	dph[n].ans=a[n];
	for(int i=n-1; i>=1; i--) {
		if(dph[i+1].ans<0) dph[i].vis=true,dph[i].ans=a[i];
		else dph[i].ans=dph[i-1].ans+a[i],dph[i].vis=false;
	}
	if(flag==true&&flag==true) {
		for(int i=1;i<=m;i++) {
			if(op[i]==1) printf("%lld\n",sum);
			else sum+=xx[i];
		}
		return 0;
	}
	int cnt=0;
	if(cnt==m) {
		for(int i=1; i<=m; i++) printf("%lld\n",dpq[xx[i]].ans+dph[xx[i]].ans-a[xx[i]]);
		return 0;
	}
	if(flagg==1) {
		int sum=0;
		for(int i=1; i<=m; i++) {
			if(op[i]==1) printf("%lld\n",dpq[xx[i]].ans+dph[xx[i]].ans-a[xx[i]]+sum);
			else sum+=xx[i];
		}
		return 0;
	}
	for(int mm=1; mm<=m; mm++) {
		if(op[mm]==1) {
			for(int i=1; i<=n; i++) {
				if(dpq[i-1].ans<0) dpq[i].vis=true,dpq[i].ans=a[i];
				else dpq[i].ans=dpq[i-1].ans+a[i],dpq[i].vis=false;
			}
			for(int i=n-1; i>=1; i--) {
				if(dph[i+1].ans<0) dph[i].vis=true,dph[i].ans=a[i];
				else dph[i].ans=dph[i-1].ans+a[i],dph[i].vis=false;
			}
			printf("%lld\n",dpq[xx[mm]].ans+dph[xx[mm]].ans-a[xx[mm]]);
		} else for(int i=1;i<=n;i++) a[i]+=xx[mm];
	}
	return 0;
}
