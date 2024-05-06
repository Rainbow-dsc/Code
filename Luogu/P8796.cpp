#include<bits/stdc++.h>
using namespace std;
int n,m,q,qu,u,v,maxx,a[10000005],c[10000005];
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1; i<=m; i++) {
        scanf("%d%d",&u,&v);
        c[u]=v;
    }
    for (int i=1; i<=n; i++) {
        if (c[i]!=0) maxx=max(c[i],maxx);
        a[i]=max(a[i],maxx);
        maxx--;
    }
    maxx=0;
    for (int i=n; i>=0; i--) {
        if(c[i]!=0) maxx=max(c[i],maxx);
        a[i]=max(a[i],maxx);
        maxx--;
    }
    for(int i=1; i<=q; i++) {
        scanf("%d",&qu);
        if(a[qu]>0) printf("%d\n",a[qu]);
        else printf("0\n");
    }
    return 0;
}
