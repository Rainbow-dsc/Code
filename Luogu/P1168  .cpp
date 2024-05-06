#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100005
int n;
vector <int> P;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%lld",&x);
		P.insert(upper_bound(P.begin(),P.end(),x),x);
		if(i%2==1) printf("%lld\n",P[(i-1)/2]);
	}
    return 0;
}
