#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
int n,l,t,sum;
struct aa {
	int x,d;
} a[maxn];
bool cmp(aa pc,aa y) {
	return pc.x<y.x;
}
int main() {
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&a[i].x,&a[i].d);
		a[i].d--;
	}
	for(int i=1; i<=n; i++) {
		if(!a[i].d) a[i].x+=t;
		else a[i].x-=t;
		sum+=a[i].x/l;
		if(a[i].x%l<0) sum--;
		a[i].x=(a[i].x%l+l)%l;
	}
	sort(a+1,a+n+1,cmp);
	sum=(sum%n+n)%n;
	for(int i=sum+1; i<=n; i++) printf("%d\n",a[i].x);
	for(int i=1; i<=sum; i++) printf("%d\n",a[i].x);
	return 0;
}

