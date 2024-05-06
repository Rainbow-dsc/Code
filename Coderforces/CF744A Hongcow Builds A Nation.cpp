#include<bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n,m,k;
int fa[maxn];
int police[maxn];
int siz[maxn];
int cnt[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=k;i++) {
		int p;
		scanf("%lld",&p);
		police[p]=1;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		int fx=find(x);
		int fy=find(y);
		fa[fx]=fy;
	}
	for(int i=1;i<=n;i++) {
		int p=find(i);
		siz[p]++;//联通块大小
		if(police[i]==1) cnt[p]++;//统计该连通块中的警局数量。
	}
	int zs=0,ans=0,add=0,a=0,b=0;
	for(int i=1;i<=n;i++) {
		if(fa[i]==i) {
			zs+=siz[i]*(siz[i]-1)/2;
			if(cnt[i]==0) add+=a*siz[i],a+=siz[i];
			else b=max(b,siz[i]);
		}
	} 
	ans=zs-m+a*b+add;
	cout<<ans;
	return 0;
}

