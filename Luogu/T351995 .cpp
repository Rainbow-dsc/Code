//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main(){
	scanf("%lld",&T);
	while(T--) {
		int n;
		scanf("%lld",&n);
		if(n==2||n==3||n==5) printf("No\n");
		else printf("Yes\n");
	}
    return 0;
}

