#include<bits/stdc++.h>
#define int long long
#define maxn 200005 
#define maxnn 500005
#define mod (int)(1e9+7)
using namespace std;
int n;
int a[maxn],vis[maxnn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        vis[a[i]]++;
    }
    sort(a+1,a+n+1);
    int cnt=unique(a+1,a+n+1)-a-1,tot=0;
    for(int i=1;i<=cnt;i++) {
        int ans=0;
        for(int j=a[i];j<=500000;j+=a[i]) ans+=vis[j];
        ans--;
        ans*=vis[a[i]]; 
        tot+=ans;   
    }
    printf("%lld",tot);
    return 0;
}