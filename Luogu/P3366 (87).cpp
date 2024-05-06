#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int u,v,w;
} edge[200005];
long long fa[5000005],n,m,ans=0,eu,ev,cnt;
bool cmp(Edge a,Edge b) {
    return a.w<b.w;
}
long long find(long long x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]]; 
    return x;
}
bool bj=false;
void kruskal() {
    sort(edge,edge+m,cmp);
    for(long long i=0; i<m; i++) {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev) continue;
        ans+=edge[i].w;
        bj=true;
        fa[ev]=eu;
    }
}
int main() {
    cin>>n>>m;
    for(long long i=1; i<=n; i++) fa[i]=i;
    for(long long i=0; i<m; i++) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    kruskal();
	if(bj==false) cout<<"orz";
	else cout<<ans;
    return 0;
}
