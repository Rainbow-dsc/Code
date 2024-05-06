#include<bits/stdc++.h>
using namespace std;
int n,m,q,s[10000001],g[10000001],ans[20000001],maxn=0;
struct aa{
	int p,a;
}c[100001];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&c[i].p,&c[i].a);
		g[c[i].p]=c[i].a;
	}
	for(int i=1;i<=n;i++) {
		if(g[i]!=0) maxn=max(maxn,g[i]);
		s[i]=max(s[i],maxn);
		maxn--;
	}
	maxn=0;
	for(int i=n;i>=1;i--) {
		if(g[i]!=0) maxn=max(maxn,g[i]);
		s[i]=max(s[i],maxn);
		maxn--;
	}
	for(int i=1;i<=q;i++){
		int Q;
		scanf("%d",&Q);
		if(s[Q]>=0) printf("%d\n",s[Q]);
		else printf("0\n");
	}
	return 0;
}
