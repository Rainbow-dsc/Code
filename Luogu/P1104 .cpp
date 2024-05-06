#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct aa{
	int id;
	string s;
	int y,m,d;
}a[105];
bool cmp(aa p,aa c) {
	if(p.y!=c.y) return p.y<c.y;
	else if(p.m!=c.m) return p.m<c.m;
	else if(p.d!=c.d) return p.d<c.d;
	else return p.id>c.id;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		cin>>a[i].s;
		cin>>a[i].y>>a[i].m>>a[i].d;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].s<<endl;
	return 0;
}

