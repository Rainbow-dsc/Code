#include<bits/stdc++.h>
#define int long long
#define maxn 1000007
using namespace std;
int n,T,L,R,cnt;
int a[maxn];
struct aa{
	int x,y,z;
}t[maxn];
signed main() {
//	freopen("star.in", "r", stdin);
//	freopen("star.out", "w", stdout);
	scanf("%lld %lld",&n,&T);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=T;i++) scanf("%lld %lld %lld",&t[i].x,&t[i].y,&t[i].z);
	scanf("%lld %lld",&L,&R);
	for(int i=T;i>=1;i--) {
		if(t[i].z==1) {
			if((L-1)%t[i].x==t[i].y)L--;
			if(R%t[i].x==t[i].y)R--;
		} else if(t[i].z==-1) {
			if(L%t[i].x==t[i].y)L++;
			if((R+1)%t[i].x==t[i].y)R++;
		}
	}
	for(int i=1;i<=n;i++) if(a[i]>=L&&a[i]<=R) cnt++;
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++) if(a[i]>=L&&a[i]<=R) printf("%lld ",i);
	return 0;
}
