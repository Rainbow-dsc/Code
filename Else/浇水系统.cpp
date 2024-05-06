#include<bits/stdc++.h>
using namespace std;

struct Node {
	double l,r;
} node[20025];
bool cmp(Node a,Node b) {
	return a.l<b.l;
}
int main() {
	int n,L,W;
	int x,r,cnt = 0;
	scanf("%d%d%d",&n,&L,&W);
	while (n--){
		scanf("%d%d",&x,&r);
		if (r>=W) {
			node[cnt].l=x*1.0-sqrt(r*r-W*W/4.0);
			node[cnt++].r=x*1.0+sqrt(r*r-W*W/4.0);
		}
	}
	sort(node,node+cnt,cmp);
	int flag=0;
	int ans=0;
	int i=0;
	double t=0;
	while (t<L){
		ans++;
		double s=t;
		while(node[i].l<=s&&i<cnt) {
			if(t<node[i].r) t=node[i].r;
			i++;
		}
		if (s==t&&s<L){
			flag=1;
			break;
		}
	}
	if(flag) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
