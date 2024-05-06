#include<bits/stdc++.h>
using namespace std;
namespace Solve {
	typedef long long ll;
	const int N=110,R=10010;
	int T,n,r[N];
	bool check(int*x) {
		int sum=0;
		for(int i=1; i<=n; i++)sum+=x[i];
		if(sum&1)return false;
		bitset<500001>f[2],g[2];
		f[0][0]=1;
		for(int i=2; i<=n; i++) {
			auto t1=g[0]<<r[i];
			g[0]|=g[1]<<r[i];
			g[1]|=t1;
			g[0]|=(f[1]<<r[i]&f[0]);
			g[1]|=(f[0]<<r[i]&f[1]);
			t1=f[0]<<r[i];
			f[0]|=f[1]<<r[i];
			f[1]|=t1;
		}
		return g[0][sum/2];
	}
	void main() {
		cin>>T;
		while(T--) {
			cin>>n;
			for(int i=1; i<=n; i++)cin>>r[i];
			if(n&1) cout<<"No\n";
			else {
				if(check(r)) cout<<"Yes\n";
				else cout<<"No\n";
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	Solve::main();
	return 0;
}
