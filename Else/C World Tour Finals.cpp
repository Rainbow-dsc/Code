#include <bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int n,m;
struct aa {
	int id;
	int q;
} a[maxn],sum[maxn];
int ans[maxn];
bool used[maxn][maxn];
bool cmp(aa x,aa y) {
	return x.q>y.q;
}
signed main() {
	memset(used,0,sizeof(used));
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=m; i++) {
		a[i].id=i;
		scanf("%lld",&a[i].q);
	}
	for(int i=1; i<=n; i++) {
		sum[i].id=i;
		for(int j=1; j<=m; j++) {
			char t;
			cin>>t;
			if(t=='o') sum[i].q+=a[j].q,used[i][j]=1;
		}
		sum[i].q+=sum[i].id;
	}
	sort(sum+1,sum+1+n,cmp);
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=n; i++) {
		if(i==1) ans[sum[1].id]=0;
		else {
			int tmp=sum[1].q-sum[i].q;
			int t1=0;
			for(int k=1; k<=m; k++) {
				if(used[sum[i].id][a[k].id]==1) {
					t1++;
					continue;
				}
				tmp-=a[k].q;
				if(tmp<=0) {
					ans[sum[i].id]=k-t1;
					break;
				}
			}
		}
	}
	for(int i=1; i<=n; i++) cout<<ans[i]<<endl;
	return 0;
}

