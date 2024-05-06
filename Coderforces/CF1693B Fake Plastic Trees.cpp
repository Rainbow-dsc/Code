#include<bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int n,T;
vector<int> P[maxn];
int l[maxn],r[maxn],val[maxn],ans;
void dfs(int x) {
    int add=0;
    for(int i=0;i<P[x].size();i++) {
        int now=P[x][i];
		dfs(now);
        add+=val[now];
    }
    if(add>=l[x]) val[x]=min(add,r[x]);
    else {
        val[x]=r[x];
        ans++;
    }
}
signed main() {
    scanf("%lld",&T);
    while(T--) {
    	memset(P,0,sizeof(P));
    	memset(val,0,sizeof(val));
		ans=0;
        scanf("%lld",&n);
        for(int i=2; i<=n; i++) {
            int fa; 
            scanf("%lld",&fa);
            P[fa].push_back(i);
        }
        for(int i=1; i<=n; i++) scanf("%lld %lld",&l[i],&r[i]);
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
