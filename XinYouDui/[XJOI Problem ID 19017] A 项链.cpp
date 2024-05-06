#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
struct LIST {
	int front,next,n,a;
	bool vis=false;
} lis[maxn];
struct aa {
	int x,y;
} pcr,rainbow;
priority_queue<aa> P;
bool operator<(aa a,aa b) {
	return lis[a.x].a+lis[a.y].a<lis[b.x].a+lis[b.y].a;
}
int T,n,m;
void delete_list(int x) {
	lis[x].vis=true;
	lis[lis[x].front].next=lis[x].next;
	lis[lis[x].next].front=lis[x].front;
}
signed main() {
	freopen("necklace.in","r",stdin);
	freopen("necklace.out","w",stdout);
	scanf("%lld%lld%lld",&T,&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&lis[i].a);
		lis[i].front=i-1;
		lis[i].next=i+1;
		lis[i].n=i;
		if(i==1) lis[i].front=n;
		if(i==n) lis[i].next=1;
	}
	m=n-m;
	for(int i=1; i<=n; i++) {
		pcr.x=i;
		pcr.y=lis[i].next;
		P.push(pcr);
	}
	for(int i=1; i<=m; i++) {
		pcr=P.top();
		P.pop();
		if(lis[pcr.x].vis==true||lis[pcr.y].vis==true) {
			i--;
			continue;
		}
		if(lis[pcr.x].a>lis[pcr.y].a) {
			delete_list(pcr.x);
			rainbow.x=lis[pcr.y].front;
			rainbow.y=pcr.y;
			P.push(rainbow);
		} else {
			delete_list(pcr.y);
			rainbow.y=lis[pcr.x].next;
			rainbow.x=pcr.x;
			P.push(rainbow);
		}
	}
	while(lis[P.top().x].vis==true||lis[P.top().y].vis==true) P.pop();
	printf("%lld",lis[P.top().x].a+lis[P.top().y].a);
	return 0;
}
