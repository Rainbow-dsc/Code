#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b,c;
signed main() {
	scanf("%lld",&t);
	for(int i=1;i<=t;i++) {
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==b) {
			printf("0\n");
			continue;
		} else {
			int p=(a+b)/2;
			int r=abs(p-max(a,b));
			if(r%c==0) cout<<r/c<<endl;
			else cout<<r/c+1<<endl; 
		}
	}
	return 0;
}

