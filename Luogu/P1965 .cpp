#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x;
int qpow(int x,int k) {
	int ans=1;
    while(k) {
        if(k&1) ans=((ans%n)*(x%n))%n;
        x=((x%n)*(x%n))%n;
        k>>=1;
    }
    return ans;
}
signed main(){
	int ans=0;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
	ans=((m%n)*(qpow(10,k)%n)+x%n)%n;
	printf("%lld",ans);
    return 0;
}
