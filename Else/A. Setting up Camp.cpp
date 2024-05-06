#include <bits/stdc++.h>
#define int long long
#define maxn (int)(2e5+7)
using namespace std;
int T;
signed main() {
	scanf("%lld",&T);
	while(T--) {
		int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(c<(3-b%3)&&b%3!=0)  printf("-1\n");
		else {
			if((b+c)%3==0) cout<<a+(b+c)/3<<endl;
			else cout<<a+(b+c)/3+1<<endl;
		}
	}
	return 0;
}

