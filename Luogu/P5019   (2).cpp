#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,ans;
int h[maxn];
signed main() {
    scanf("%lld",&n);
    for(int i=1; i<=n; i++) scanf("%lld",&h[i]);
    for(int i=1; i<=n; i ++) if(h[i]>h[i-1]) ans+=(h[i]-h[i-1]); 
    printf("%lld",ans);
    return 0;
}
