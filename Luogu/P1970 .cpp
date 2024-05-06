#include<bits/stdc++.h>
#define maxn 100010
#define int long long
using namespace std;
int a[maxn],f[maxn][2];
int n,tmp=0;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    f[1][0]=f[1][1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) f[i][0]=f[i-1][1]+1;
        else f[i][0]=f[i-1][0];
        if(a[i]<a[i-1]) f[i][1]=f[i-1][0]+1;
        else f[i][1]=f[i-1][1];
    }
    printf("%lld",max(f[n][0],f[n][1]));
    return 0;
}
