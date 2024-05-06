#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,op;
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&op);
	printf("%lld",m%mod*n%mod-1);
	return 0;
}
