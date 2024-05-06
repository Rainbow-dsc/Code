#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define MAXN 500005
using namespace std;
struct LIST {
	int front,next,n,a,chosen;
} lst[MAXN];
struct Node {
	int x,y;
} node,top;
bool operator<(Node a,Node b) {
	return lst[a.x].a+lst[a.y].a<lst[b.x].a+lst[b.y].a;
}
priority_queue<Node> q;
int ID,n,m;
inline void list_delete(int x) {
	lst[lst[x].front].next=lst[x].next;
	lst[lst[x].next].front=lst[x].front;
	lst[x].chosen=1;
	return ;
}
signed main() {
//	 freopen("necklace.in","r",stdin);
//	 freopen("necklace.out","w",stdout);
	scanf("%lld%lld%lld",&ID,&n,&m);
	m=n-m;
	for(register int i=1; i<=n; i++) {
		scanf("%lld",&lst[i].a);
		lst[i].n=i;
		lst[i].front=i-1;
		lst[i].next=i+1;
	}
	lst[1].front=n;
	lst[n].next=1;
	for(register int i=1; i<=n; i++) {
		node.x=i;
		node.y=lst[i].next;
		q.push(node);
	}
	for(register int i=1; i<=m; i++) {
		top=q.top();
		q.pop();
		if(lst[top.x].chosen||lst[top.y].chosen) {
			i--;
			continue;
		}
		if(lst[top.x].a>lst[top.y].a) {
			list_delete(top.x);
			node.x=lst[top.y].front;
			node.y=top.y;
			q.push(node);
		} else {
			list_delete(top.y);
			node.x=top.x;
			node.y=lst[top.x].next;
			q.push(node);
		}
	}
	while(lst[q.top().x].chosen||lst[q.top().y].chosen) q.pop();
	printf("%lld\n",lst[q.top().x].a+lst[q.top().y].a);
	return 0;
}
