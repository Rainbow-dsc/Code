#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001];
bool bj[10001];
signed main() {
	scanf("%lld",&n);
	memset(bj,false,sizeof(bj));
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++) if(abs(a[i]-a[i+1])<=n-1&&abs(a[i]-a[i+1])>=1)  bj[abs(a[i]-a[i+1])]=true;
	for(int i=1;i<n;i++) {
		if(bj[i]==false) {
			cout<<"Not jolly";	
			return 0;
		}
	}
	cout<<"Jolly";
	return 0;
}

