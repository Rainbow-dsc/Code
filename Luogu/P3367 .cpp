#include<bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n,m;
int fa[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int z,x,y;
		scanf("%lld %lld %lld",&z,&x,&y);
		if(z==1) {
			int fx=find(x);
			int fy=find(y);
			fa[fx]=fy;
		}
		if(z==2) {
			if(find(x)==find(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}

