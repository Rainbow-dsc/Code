#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int t;
int c[maxn];
bool used[maxn];
int ans[maxn];
struct aa{
	int x,id;
}a[maxn];
bool cmp(aa p,aa c) {
	if(p.x!=c.x) return p.x<c.x;
	else return p.id>c.id;
} 
signed main() {
	scanf("%lld",&t);
	while(t--) {
		int n,k;
		memset(used,0,sizeof(used));
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) {
			scanf("%lld",&c[i]);
			a[i].id=i;
			a[i].x=c[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=n;i++) {
			if(a[i].x==a[i-1].x) used[i]=1; 
		}
		scanf("%lld",&k);
		int mod=k%a[1].x;
		int sum=k/a[1].x;
		if(sum==0) {
			for(int i=1;i<=n;i++) cout<<0<<" ";
			puts("");
			continue;
		}
		else {
			int sum1=sum-1;
			int mod1=mod+a[1].x;
			int pc=n;
			for(int i=2;i<=n;i++) {
				if(mod1<a[i].x) {
					pc=i-1;
					break;
				}
			}
			for(int i=pc;i>=1;i--) {
				if(used[i]==0) {
					pc=i;
					break;
				} 
			}
			for(int i=1;i<=a[1].id;i++) ans[i]+=sum1;
			for(int i=1;i<=a[pc].id;i++) ans[i]+=1;
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

