#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,m1,m2;
struct aa {
	int x,y;
} a[maxn],b[maxn];
int res1[maxn],res2[maxn];
bool cmp(aa x,aa y) {
	return x.x<y.x;
}
void rainbow1() {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> P;
	priority_queue<int,vector<int>,greater<int >> C;
	for(int i=1; i<=n; i++) C.push(i);
	for(int i=1; i<=m1; i++) {
		while(!P.empty()&&a[i].x>=P.top().first) {
			C.push(P.top().second);
			P.pop();
		}
		if(C.empty()) continue;
		int now=C.top();
		C.pop();
		res1[now]++;
		P.push(make_pair(a[i].y,now));
	}
	for(int i=1; i<=n; i++) res1[i]+=res1[i-1];
}
void rainbow2() {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> P;
	priority_queue<int,vector<int>,greater<int >> C;
	for(int i=1; i<=n; i++) C.push(i);
	for(int i=1; i<=m2; i++) {
		while(!P.empty()&&b[i].x>=P.top().first) {
			C.push(P.top().second);
			P.pop();
		}
		if(C.empty()) continue;
		int now=C.top();
		C.pop();
		res2[now]++;
		P.push(make_pair(b[i].y,now));
	}
	for(int i=1; i<=n; i++) res2[i]+=res2[i-1];
}
signed main() {
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1; i<=m2; i++) scanf("%lld%lld",&b[i].x,&b[i].y);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	rainbow1();
	rainbow2();
	int ans=0;
	for(int i=0; i<=n; i++) ans=max(ans,res1[i]+res2[n-i]);
	printf("%lld\n",ans);
	return 0;
}
