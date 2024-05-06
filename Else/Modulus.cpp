#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r;
long long a[10000000];
int main() {
    scanf("%d%d",&n,&m);
    if(n<=100001) for(long long i=1; i<=n; i++) a[i]=n%i;
    for(long long k=1; k<=m; k++) {
        long long maxn=0;
        scanf("%d%d",&l,&r);
        if(l==r){
            printf("%d\n",n%l);
            continue;
        }
        for(long long i=l; i<=r; i++) maxn=max(maxn,a[i]);
        printf("%d\n",maxn);
    }
    return 0;
}
