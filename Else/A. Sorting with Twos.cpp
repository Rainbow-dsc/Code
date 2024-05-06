#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[10000001];
signed main() {
	cin>>t;
	while(t--) {
		int f=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			if(f) continue;
			if(i==2||i==3||i==5||i==9||i==17) continue;
			if(a[i-1]>a[i]) f=1;
		}
		if(f==1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
