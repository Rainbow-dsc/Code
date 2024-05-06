#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct aa{
	int id;
	int rk;
}a[1005];
bool cmp(aa x,aa y) {
	if(x.rk!=y.rk) return x.rk>y.rk;
	else return x.id<y.id;
}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		a[i].id=i;
		for(int j=1;j<=n;j++) {
			char x;
			cin>>x;
			if(x=='o') a[i].rk++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].id<<" ";
	return 0;
}

