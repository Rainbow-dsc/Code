#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt;
signed main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	scanf("%lld",&n);
	for(register int i=2;i<=n;i++) {
		int x=i*i-1;
		for(register int j=1;j<=n;j++) {
			if(x%j==0&&x!=0&&x/j<=n) cnt++;
		}
	}
	printf("%lld",cnt);
    return 0;
}
