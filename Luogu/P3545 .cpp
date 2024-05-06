#include<bits/stdc++.h>
#define int long long
#define maxn 250005
using namespace std;
int n;
int a[maxn],b[maxn];
bool vis[maxn];
struct aa {
	int a,id;
	bool operator <(const aa &x) const {
		if(x.a!=a) return x.a>a;
		else return x.id>id; 
	}
};
priority_queue <aa> C;
signed main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
	int tot=0,cnt=0;
	for(int i=1; i<=n; i++) {
		tot+=a[i];
		if(tot<b[i]&&!C.empty()&&C.top().a>b[i]) {
			vis[C.top().id]=false;
			tot+=C.top().a;
			C.pop();
			cnt--;
		}
		if(tot>=b[i]) {
			tot-=b[i];
			C.push({b[i],i});
			vis[i]=true;
			cnt++;
		}
	}
	printf("%lld\n",cnt);
	for(int i=1; i<=n; i++) if(vis[i]) printf("%lld ",i);
	return 0;
}
