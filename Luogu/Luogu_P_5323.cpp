#include<bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
using namespace std;
int n;
int inv(int x) {
    int a=1;
    for(int e=mod-2;e;e>>=1,x=x*x%mod) if(e%2==1) a=a*x%mod;
    return a;
}
signed main(){
    scanf("%lld",&n);
    int p=1,q=0;
    while(n--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        a=a*inv(100)%mod,b=b*inv(100)%mod;
        int x=inv((1-q*b%mod+mod)%mod);
        q=(b+a*a%mod*q%mod*x)%mod;
        p=p*a%mod*x%mod;
    }
    printf("%lld",p);
    return 0;
}