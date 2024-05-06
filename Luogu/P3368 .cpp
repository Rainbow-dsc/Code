#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,q,a[maxn],tr[maxn];
int  lowbit(int p) {
	return p&-p;
}
void update(int s,int p) {
	for(int i=s;i<=n;i+=lowbit(i)) tr[i]+=p;
}
int  Query(int p) {
	int ans=0;
	for(int i=p;i>=1;i-=lowbit(i)) ans+=tr[i];
	return ans;
}
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=q;i++) {
		int opt;
		scanf("%lld",&opt);
		if(opt==1) {
			int x,y,s;
			scanf("%lld%lld%lld",&x,&y,&s);
			update(x,s);
			update(y+1,-s);
		}
		else {
			int x;
			scanf("%lld",&x);
			printf("%lld\n",a[x]+Query(x));
		}
	}
	return 0;
}
