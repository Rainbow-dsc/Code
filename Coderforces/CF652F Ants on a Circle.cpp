#include<bits/stdc++.h>
#define int long long
#define maxn 300005
using namespace std;
int n,m,t,ans[maxn],eid;
char ch;
struct ant { int x,d,id; } a[maxn],e[maxn];
bool cmp(ant a,ant b) { return a.x<b.x; }
signed main() {
	scanf("%lld %lld %lld",&n,&m,&t);
	for(int i=1; i<=n; i++) {
		scanf("%lld %c",&a[i].x,&ch);
		a[i].id=i;
		if(ch=='L') {
			a[i].d=e[i].d=-1;
			eid=((eid-(t+m-a[i].x)/m)%n+n)%n;
			e[i].x=((a[i].x-t)%m+m-1)%m+1;
		} else {
			a[i].d=e[i].d=1;
			eid=(eid+(t+a[i].x-1)/m)%n;
			e[i].x=((a[i].x+t)%m+m-1)%m+1;
		}
	}
	sort(a+1,a+n+1,cmp);
	sort(e+1,e+n+1,cmp);
	for(int i=1; i<=n; i++) ans[a[i].id]=e[(i+eid-1)%n+1].x;
	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
	return 0;
}
