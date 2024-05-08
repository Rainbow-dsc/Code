#include<bits/stdc++.h>
#define int long long
#define maxn 2000005
#define mod (int)(1e9+7)
using namespace std;
int n,k;
struct aa{
    int opt,x,aA;
    bool operator < (aa b) const {return aA<b.aA;}
}a[maxn];
bool vis[maxn];
signed main(){
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i].aA);
        a[i].x=i;
        a[i].opt=1;
    }
    for(int i=n+1;i<=2*n;i++) {
        scanf("%lld",&a[i].aA);
        a[i].x=i-n;
    }
    sort(a+1,a+2*n+1);
    int l=0,r=2*n+1,now=0;
    while(vis[a[l+1].x]==false&&now+a[l+1].opt<=k) now+=a[l+1].opt,vis[a[l+1].x]=true,l++;
    while(vis[a[r-1].x]==false&&now+a[r-1].opt<=k) now+=a[r-1].opt,vis[a[r-1].x]=true,r--;
    int ans=1e18;
    while(l>=0) {
        ans=min(ans,a[r-1].aA-a[l+1].aA);
        vis[a[l].x]=false;
        now-=a[l].opt;
        l--;
        while(vis[a[r-1].x]==false&&now+a[r-1].opt<=k) now+=a[r-1].opt,vis[a[r-1].x]=true,r--;
    }
    printf("%lld",ans);
    return 0;
}