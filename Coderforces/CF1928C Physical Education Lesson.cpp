#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t,n,x;
set<int> s;
signed main() {
	scanf("%lld",&t);
	while(t--) {
		s.clear();
		scanf("%lld %lld",&n,&x);
		int g1=n-x,g2=n+x-2;
		for(int i=1; i*i<=g1; i++) {
			if(g1%i==0) {
				if(i%2==0&&(i+2)/2>=x) s.insert((i+2)/2);
				if((g1/i)%2==0&&(g1/i+2)/2>=x) s.insert((g1/i+2)/2);
			}
		}
		for(int i=1; i*i<=g2; i++) {
			if(g2%i==0) {
				if(i%2==0&&(i+2)/2>=x) s.insert((i+2)/2);
				if((g2/i)%2==0&&(g2/i+2)/2>=x) s.insert((g2/i+2)/2);
			}
		}
		printf("%lld\n",s.size());
	}
	return 0;
}

