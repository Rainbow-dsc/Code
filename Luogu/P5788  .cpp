#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[3000001],f[3000001];
stack<int> s;
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--) {
		while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
		if(s.empty()) f[i]=0;
		else f[i]=s.top();
		s.push(i); 
	}
	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	return 0;
}

