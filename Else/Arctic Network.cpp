#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,fa[500005]= {0},jc=0,xx[500005],yy[500005],jc1=0;
double ans[500005]= {0};
int find(int x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
struct node {
    int u;
    int v;
    double w;
} edge[500005];
bool comp(node x,node y) {
    return x.w<y.w;
}
int main() {
    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++) {
        cin>>m>>n;
        for(int i=1; i<=n; i++)
            fa[i]=i;
        for(int i=1; i<=n; i++) {
            cin>>xx[i]>>yy[i];
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i!=j) {
                    edge[++jc1].u=i;
                    edge[jc1].v=j;
                    edge[jc1].w=sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
                }
            }
        }
        sort(edge+1,edge+jc1+1,comp);
        for(int i=1; i<=jc1; i++) {
            int u=find(edge[i].u);
            int v=find(edge[i].v);
            double w=edge[i].w;
            if(u!=v) {
                cnt++;
                fa[u]=v;
                ans[++jc]=w;
            }
        }
        if(m<n)
            printf("%.2lf\n",ans[jc-m+1]);
        else cout<<0.00;
        jc=0;
        jc1=0;
        cnt=0;
        memset(fa,0,sizeof(fa));
        memset(ans,0,sizeof(ans));
        memset(xx,0,sizeof(xx));
        memset(yy,0,sizeof(yy));
        memset(edge,0,sizeof(edge));
    }
    return 0;
}
