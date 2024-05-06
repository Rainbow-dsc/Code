#include<bits/stdc++.h>
using namespace std;
vector<int> w[100001];
int n,r,q;
int a[1005];
struct aa{
	int x,y;
}e[1005];
struct xun{
	string s;
	int b,c,d;
}p[100001];
int main(){
	cin>>n>>r>>q;
	for(int i=1;i<=n-1;i++) {
		scanf("%d%d",&e[i].x,&e[i].y);
		w[e[i].x].push_back(e[i].y);
		w[e[i].y].push_back(e[i].x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		scanf("%s",&p[i].s);
		if(p[i].s[0]=='C') {
			scanf("%d%d",&p[i].b,&p[i].c);
			a[p[i].b]=p[i].c;
		}
		if(p[i].s[0]=='Q'){
			scanf("%d",&p[i].d);
			
		}
	}
	return 0;
}
