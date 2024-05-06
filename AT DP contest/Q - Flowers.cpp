#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define mod (int)(1e9+7)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int n;
int a[maxn],h[maxn];
int dp[maxn];
int maxx[maxn<<2];
void push_up(int rt) {maxx[rt]=max(maxx[lc],maxx[rc]);}
void update(int l,int r,int pos,int rt,int val) {
    if(l==r) {
        maxx[rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,pos,lc,val);
    else update(mid+1,r,pos,rc,val);
    push_up(rt);
    return ;
}
int query(int l,int r,int s,int t,int rt) {
    if(l<=s&&t<=r) return maxx[rt];
    int res=0,mid=(s+t)>>1;
    if(l<=mid) res=max(query(l,r,s,mid,lc),res);
    if(r>mid) res=max(query(l,r,mid+1,t,rc),res);
    return res; 
}
signed main(){
    int ans=-1e18;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),dp[i]=a[i];
    for(int i=1;i<=n;i++) {
        int res=query(1,h[i],1,n,1);
        dp[i]=res+a[i];
        ans=max(ans,dp[i]);
        update(1,n,h[i],1,dp[i]);
    }
    printf("%lld",ans);
    return 0;
}