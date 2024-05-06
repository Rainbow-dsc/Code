#include <bits/stdc++.h>
#define int long long
#define maxn 400005
using namespace std;
int n;
int tr[4000005][2],cnt=0,ans=-1;
struct aa{int v,w;};
vector<aa> P[maxn];
void insert(int x) {
    int u=0;
    for(int i=30;i>=0;i--) {
        if(x&(1<<i)) {
            if(tr[u][1]) u=tr[u][1];
            else cnt++,tr[u][1]=cnt,u=cnt;
        } else {
            if(tr[u][0]) u=tr[u][0];
            else cnt++,tr[u][0]=cnt,u=cnt;
        }
    }
}
void dfs(int x,int fa,int sum) {
    insert(sum);
    for(int i=0;i<P[x].size();i++) {
        aa to=P[x][i];
        if(to.v!=fa) dfs(to.v,x,sum^to.w);
    }
}
void get(int u1,int u2,int sum,int deep) {
    if(deep==-1) ans=max(ans,sum);
    if((tr[u1][0]&&tr[u2][1])||(tr[u1][1]&&tr[u2][0])) {
        if(tr[u1][0]&&tr[u2][1]) get(tr[u1][0],tr[u2][1],sum|(1<<deep),deep-1);
        if(tr[u1][1]&&tr[u2][0]) get(tr[u1][1],tr[u2][0],sum|(1<<deep),deep-1);
    } else {
		if(tr[u1][0]&&tr[u2][0]) get(tr[u1][0],tr[u2][0],sum,deep-1);
		if(tr[u1][1]&&tr[u2][1]) get(tr[u1][1],tr[u2][1],sum,deep-1);
	}
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++) {
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        P[u].push_back({v,w});
        P[v].push_back({u,w});
    }
    dfs(1,0,0);
    get(0,0,0,30);
    printf("%lld",ans);
    return 0;
}
