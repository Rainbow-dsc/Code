#include<bits/stdc++.h>
#define int long long
#define maxn (int)(2e6+5)
using namespace std;
int n,ans;
char a[maxn];
int pre[maxn],w[maxn];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) { int p=i;while(p) { if(a[p-1]==a[i]) {pre[i]=p-1;break;}p=pre[p-1];}w[pre[i]]++; }
    for(int i=n;i>=1;i--) ans+=w[i],w[pre[i-1]]+=w[i];
    printf("%lld",ans);
    return 0;
}