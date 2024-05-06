#include<bits/stdc++.h>
#define int long long
#define maxn (int)(1e7)
using namespace std;
int n,m,maxx,ans;
int a[maxn];
signed main(){
    scanf("%lld %lld",&n,&m);
    while(m--) {
        int l,r,s,e;
        scanf("%lld %lld %lld %lld",&l,&r,&s,&e);
        int x=(e-s)/(r-l);
        a[l]+=s,a[l+1]-=s,a[l+1]+=x;
        a[r+1]-=x,a[r+1]-=e,a[r+2]+=e;
    }
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    for(int i=1;i<=n;i++) {
        a[i]+=a[i-1];
        maxx=max(maxx,a[i]),ans^=a[i];
    }
    printf("%lld %lld",ans,maxx);
    return 0;
}