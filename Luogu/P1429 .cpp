#include<bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int n;
double ans=(double)(2e9+7);
struct aa{ int x,y; }a[maxn];
bool cmp(aa xx,aa y) {
	return xx.x<y.x;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			double dx=abs(a[i].x-a[j].x),dy=abs(a[i].y-a[j].y);
			if(ans<dx) break;
			ans=min(ans,sqrt(dx*dx+dy*dy));
		}
	}
	printf("%.4lf",ans);
	return 0;
}
