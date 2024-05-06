#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct aa{
	double x,y,z;
}a[500001];
bool cmp(aa p,aa c) {
	return p.z<c.z;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+n+1,cmp);
	double ans=0.000;
	for(int i=1;i<n;i++) ans+=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y)+(a[i].z-a[i+1].z)*(a[i].z-a[i+1].z));
	printf("%.3lf",ans);
	return 0;
}

