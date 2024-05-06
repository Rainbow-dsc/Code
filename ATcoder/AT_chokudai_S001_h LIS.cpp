#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define mod (int)(1e9+7)
using namespace std;
int n,a[maxn],x;
int s[maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int cnt=0;
    s[++cnt]=a[1];
    for(int i=2;i<=n;i++) {
        if(a[i]>s[cnt]) s[++cnt]=a[i];
        else {
            x=lower_bound(s+1,s+cnt+1,a[i])-s;
            s[x]=a[i];
        }
    }
    printf("%lld",cnt);
    return 0;
}