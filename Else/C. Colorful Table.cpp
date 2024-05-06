#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t;
int a[maxn],c[maxn],used[maxn],used1[maxn];
bool Used[maxn];
signed main() {
	scanf("%lld",&t);
	while(t--) {
		int n,k;
		int top=1;
		memset(used,0,sizeof(used));
		memset(Used,false,sizeof(Used));
		memset(used1,0,sizeof(used1));
		scanf("%lld%lld",&n,&k);
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			Used[a[i]]=true;
		}
		for(int i=1; i<=n; i++) {
			if(top<=a[i]) {
				for(int j=top; j<=a[i]; j++) used[j]=i;
				top=a[i]+1;
			}
		}
		for(int i=1; i<=n; i++) {
			if(used[a[i]]>=i) used[a[i]]=i;
		}
		top=1;
		for(int i=n; i>=1; i--) {
			if(top<=a[i]) {
				for(int j=top; j<=a[i]; j++) {
					used1[j]=i;
				}
				top=a[i]+1;
			}
		}
		for(int i=n; i>=1; i--) {
			if(used1[a[i]]<=i) used1[a[i]]=i;
		}
		for(int i=1; i<=k; i++) {
			if(Used[i]==false) cout<<0<<" ";
			else {
				int ans=2*(used1[i]-used[i]+1);
				printf("%lld ",ans);
			}
		}
//		if(n==3&&k==5) {
//			cout<<endl<<used1[3]<<" "<<used[3];
//		}
		puts("");
	}
	return 0;
}

